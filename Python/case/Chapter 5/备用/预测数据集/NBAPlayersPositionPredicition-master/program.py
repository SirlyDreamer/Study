import pandas as pd
import numpy as np

from keras.models import Sequential
from keras.layers import Dense, Activation, Dropout

from sklearn.neighbors import KNeighborsClassifier
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
from sklearn.ensemble import RandomForestClassifier
from sklearn.tree import DecisionTreeClassifier

from sklearn.naive_bayes import GaussianNB, BernoulliNB, MultinomialNB
from sklearn.svm import SVC

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelBinarizer, StandardScaler, LabelEncoder, OneHotEncoder

from sklearn import datasets, linear_model
from sklearn.metrics import accuracy_score, f1_score, confusion_matrix, classification_report
from sklearn.model_selection import KFold
from sklearn.model_selection import GridSearchCV
from sklearn.pipeline import Pipeline
from sklearn.ensemble import ExtraTreesClassifier

from sklearn.feature_selection import SelectKBest,SelectFromModel
from sklearn.feature_selection import chi2, f_classif, mutual_info_classif



import matplotlib.pyplot as plt
from matplotlib.mlab import PCA

def preparing_rookes():
	players = pd.read_csv('Datasets/Players.csv', index_col=0)
	rookies = pd.read_csv('Datasets/Results.csv', index_col=0)
	
	
	
	rookies = pd.merge(rookies, players[['Player', 'height', 'weight']], left_on='Player', right_on='Player', how='left')
	rookies = rookies.fillna(value=0)
	rookies = rookies.drop(['blanl', 'blank2', 'Tm', 'Age'], axis='columns')
	
	
	rookies = rookies[rookies['Player'] != 0]
	filter = (rookies['Pos']=="PG") | (rookies['Pos']=="SG") | (rookies['Pos']=="SF") | (rookies['Pos']=="PF") | (rookies['Pos']=="C")
	rookies = rookies[filter]	
	return rookies

def preparing_dataset():
	players = pd.read_csv('Datasets/Players.csv', index_col=0)
	stats = pd.read_csv('Datasets/Seasons_Stats.csv', index_col=0)
	
	
	data = pd.merge(stats, players[['Player', 'height', 'weight']], left_on='Player', right_on='Player', how='left')
	data = data.fillna(value=0)
	data = data.drop(['blanl', 'blank2', 'Tm', 'Age'], axis='columns')

	#Removing all rows on year change in dataset (there was row with just ID)
	data = data[data['Player'] != 0]
	
	data = data.drop_duplicates(subset=['Player', 'Year'], keep='first', inplace=False)
	filter = (data['Pos']=="PG") | (data['Pos']=="SG") | (data['Pos']=="SF") | (data['Pos']=="PF") | (data['Pos']=="C")
	
	data = data[filter]
	
	#Removing a star sign at the end of the names of some players
	data['Player'] = data['Player'].str.replace('*','')
	
	data.reset_index(inplace=True, drop=True)
	return data	
#60-75 (71) za 1980
def remove_by_minutes(data, minutes=71): 
	filter = data['MP']>=minutes; 
	data = data[filter]
	return data;

def remove_by_year(data,year=1980):
	filter = data['Year'] >= year
	data = data[filter]
	return data;
	
def correct_FG_percentage (data, field_goals_attempts=30):
	data.loc[data['FGA'] <= field_goals_attempts,'FG%'] = data['FG%'].mean()
	return data
	
def correct_FT_percentage (data, free_throws_attempts=20):
	data.loc[data['FTA'] <= free_throws_attempts,'FT%'] = data['FT%'].mean()
	return data
	
def prepare_totals(data,minutes_to_mull=36):
	totals = ['PER', 'OWS', 'DWS', 'WS', 'OBPM', 'DBPM', 'BPM', 'VORP', 'FG', 'FGA', '3P', '3PA', '2P', '2PA', 'FT', 'FTA', 'ORB', 'DRB', 'TRB', 'AST', 'STL', 'BLK', 'TOV', 'PF', 'PTS']
	for col in totals:
		data[col] = minutes_to_mull*data[col]/data['MP']
	return data;


def note_results(results, path, encoder):
	test_stats_filter = data['Year'] == test_seasion
	test_stats =  data[test_stats_filter]
	test_stats = rookies_data
	print('Data stats')
	#print (test_stats)
	idx = test_stats['Player'].values
	real = test_stats['Pos'].values
	results_str = encoder.inverse_transform(results)
	test_result_data = pd.DataFrame(index=idx, data={'Real': real, 'Predicted': results_str})
	test_result_data.to_csv(path, sep=',')
	count = len(test_result_data)
	hit_count = len(test_result_data[test_result_data['Real'] == test_result_data['Predicted']])
	print ("Redovni: \t", hit_count, "/", count, "(", round (accuracy_score(real,results_str)*100,3), "%)")
	print ('F1 measure    ', round(f1_score(real,results_str, average ='weighted')*100,3))
	
	
		#TODO za susedne
	#miss = test_result_data[test_result_data['Real'] != test_result_data['Predicted']]
	#hit_neighbors = hit_count;
	#for idx in miss.index:
	#	[pos1, pos2] = miss.loc[idx]
	#	if(is_heighbors(pos1,pos2)):
	#		hit_neighbors=hit_neighbors+1
	#print ("Susedni:\t", hit_neighbors, "/",count , "(", round((hit_neighbors/count)*100,3), "%)")	
	#return 100*accuracy_score(real,results_str)
	
def is_heighbors (pos1, pos2):
	if pos1=='PG':
		if pos2== 'SG':
			return True
	if pos1=='SG':
		if (pos2=='PG') | (pos2 =='SF'):
			return True
	if pos1=='SF':
		if (pos2=='SG') | (pos2 =='PF'):
			return True
	if pos1=='PF':
		if (pos2=='SF') | (pos2 =='C'):
			return True
	if pos1=='C':
		if pos2 == 'PF':
			return True
	return False
		
def predict(model, X_train, y_train, X_test):
	model.fit(X_train,y_train)
	
	#print (X_train.shape)
	#model.feature_importances_
	#X_train = SelectFromModel(model, prefit=True).transform(X_train)
	model_results = model.predict(X_test)
	
	#print (X_train.shape)
	#print('Test data score', round(accuracy_score(y_train,model.predict(X_train))*100,3))
	#print ('jednu')	
	return model_results

######################################

def split_sets(encoder, auto_select = False, features_number=10, algorithm = f_classif):
	X = data.drop(['Pos', 'Player'], axis=1).as_matrix()
	y = data['Pos'].as_matrix()
	
	X_rookies = rookies_data.drop(['Pos', 'Player'], axis=1).as_matrix()
	y_rookies = rookies_data['Pos'].as_matrix()
	
	print ('Rookies')
	#print (X_rookies)
	y_encoded = encoder.fit_transform(y)
	X_scaled = scaler.fit_transform(X)
	
	y_encoded_r = encoder.fit_transform(y_rookies)
	X_scaled_r = scaler.fit_transform(X_rookies)

	if auto_select:
		print ()
		#X_scaled = SelectKBest(algorithm, k=features_number).fit_transform(X_scaled,y_encoded)

	test_stats_filter = data['Year'] == test_seasion
	X_train = X_scaled[~test_stats_filter]
	y_train = y_encoded[~test_stats_filter]
	
	#X_test = X_scaled[test_stats_filter]
	#y_test = y_encoded[test_stats_filter]
	
	X_test = X_scaled_r
	y_test = y_encoded_r
	return [X_train, y_train, X_test, y_test]
	
def test_KNN(encoder):
	KNN.n_neighbors = 23;
	KNN.p = 1
	KNN.weights = 'distance'
	X_train, y_train, X_test, y_test = split_sets(encoder, True, 15, f_classif)
	print('\n------------------- KNN results -----------------------')
	k_fold_cross_validation(KNN, encoder, X_train, y_train)
	test(KNN, encoder, X_train, y_train, X_test, 'KNN_results.csv')
	
def test_naive_bayes(encoder):
	X_train, y_train, X_test, y_test = split_sets(encoder,False)
	print('\n---------------- Naive Bayes results ------------------')	
	#k_fold_cross_validation(naive_bayes, encoder, X_train, y_train)
	test(naive_bayes, encoder, X_train, y_train, X_test, 'naive_bayes_results.csv')

def test_LDA(encoder):
	LDA.solver = 'eigen'
	LDA.shrinkage = 0.035
	print('\n-------------------- LDA results ----------------------')
	k_fold_cross_validation(LDA, encoder, X_train, y_train)
	test(LDA, encoder, X_train, y_train, X_test, 'LDA_results.csv')
	
def test_DTC(encoder):
	DTC.min_samples_leaf = 2
	DTC.criterion = 'entropy'
	DTC.max_depth = 8
	X_train, y_train, X_test, y_test = split_sets(encoder, True, 16, mutual_info_classif)
	print('\n-------------------- DTC results ----------------------')
	k_fold_cross_validation(DTC, encoder, X_train, y_train)
	test(DTC, encoder, X_train, y_train, X_test, 'DTC_results.csv')

def test_RFC(encoder):
	RFC.n_estimators = 100
	RFC.max_features = 'auto'
	RFC.criterion = 'gini'
	X_train, y_train, X_test, y_test = split_sets(encoder, False)
	print(RFC.criterion, RFC.n_estimators, RFC.max_features)
	print('\n-------------------- RFC results ----------------------')
	k_fold_cross_validation(RFC, encoder, X_train, y_train)
	test(RFC, encoder, X_train, y_train, X_test, 'RFC_results.csv')
	
		
def test_SVC(encoder):
	SVC.c = 2.3;
	SVC.kernel = 'rbf'
	X_train, y_train, X_test, y_test = split_sets(encoder, False)
	print('\n------------------- SVC results -----------------------')
	k_fold_cross_validation(SVC, encoder, X_train, y_train)
	test(SVC, encoder, X_train, y_train, X_test, 'SVC_results.csv')	
	
def test_SEQ(encoder, epochs = 200, batch_size = 128):	
	X_train, y_train, X_test, y_test = split_sets(encoder, False)
	columns_count = X_train.shape[1]
	SEQ.add(Dense(40, activation='relu', input_dim=columns_count))
	SEQ.add(Dropout(0.5))
	SEQ.add(Dense(30, activation='relu'))
	SEQ.add(Dropout(0.5))
	SEQ.add(Dense(len(encoder.classes_), activation='softmax'))
	SEQ.compile(loss='categorical_crossentropy', optimizer='sgd', metrics=['accuracy'])

	k_fold_cross_validation(SEQ, encoder, X_train, y_train, epochs, batch_size)
	
	
	#test(SEQ, encoder, X_train, y_train, X_test, 'SEQ_results.csv')	
	
	
def k_fold_cross_validation(model,encoder,X, Y, epochs = 200, batch_size = 128):
	k = 10
	k_fold = KFold(n_splits = k, random_state=None, shuffle=False)
	acc_sum = 0;
	f1_sum = 0;
	for train_index, val_index in k_fold.split(X):
		X_train, X_val = X[train_index], X[val_index]
		y_train, y_val = Y[train_index], Y[val_index]
		if (model == SEQ):		
			model.fit(X_train, y_train, epochs=epochs, batch_size=batch_size, validation_split =0, verbose= 0)
			predict_results = model.predict(X_val)
			predict_results = encoder.inverse_transform(predict_results)
			y_val = encoder.inverse_transform(y_val)
			#print('Test data score', round(accuracy_score(encoder.inverse_transform(y_train),encoder.inverse_transform(model.predict(X_train)))))
		if (model != SEQ):
			predict_results = predict(model,X_train,y_train, X_val)
		#print('Accuracy score', round(accuracy_score(y_val,predict_results)*100,3))
		#print('F1 measure    ', round(f1_score(y_val,predict_results, average ='weighted')*100,3))
		#print('Classif report', classification_report(y_val,predict_results)*100,3)
		#print('Confusion matr\n', confusion_matrix(y_val,predict_results))
		#print('\n')
		acc_sum = acc_sum + accuracy_score(y_val,predict_results)
		f1_sum = f1_sum + f1_score(y_val,predict_results, average ='weighted')
		
	print('Acc score  AVG', round((acc_sum/k)*100,3))
	print('F1 measure AVG', round((f1_sum/k)*100,3))
	
	
	if (model == KNN):
		accKNN.append((acc_sum/k)*100)
	if (model == SVC):
		accSVC.append((acc_sum/k)*100)
	if (model == DTC):
		accDTC.append((acc_sum/k)*100)
		
	acc.append((acc_sum/k)*100)
	f1s.append((f1_sum/k)*100)
	

def test (model, encoder, X_train, y_train, X_test, path):
	print ()
	if (model != SEQ):
		model_results = predict(model, X_train, y_train, X_test)
	if (model == SEQ):
		SEQ.fit(X_train, y_train, epochs=200, batch_size=128, validation_split=0, verbose=1)
		model_results = SEQ.predict(X_test)
		print('\n-------------------- SEQ results ----------------------')
		print('Test data score', round(accuracy_score(encoder.inverse_transform(y_train),encoder.inverse_transform(SEQ.predict(X_train)))))
	note_results(model_results,path, encoder)

####################################################################################
def is_good_to_remove(cat):
	PGs = data[data["Pos"] == "PG"]
	SGs = data[data["Pos"] == "SG"]
	SFs = data[data["Pos"] == "SF"]
	PFs = data[data["Pos"] == "PF"]
	CCs = data[data["Pos"] == "C"]
	
	print (cat)
	PGPointSum = sum(PGs[cat])
	SGPointSum = sum(SGs[cat])
	SFPointSum = sum(SFs[cat])
	PFPointSum = sum(PFs[cat])
	CCPointSum = sum(CCs[cat])
	print ("PG",PGPointSum /len(PGs))
	print ("SG",SGPointSum /len(SGs))
	print ("SF",SFPointSum /len(SFs))
	print ("PF",PFPointSum /len(PFs))
	print ("CC",CCPointSum /len(CCs))

	#exit()

def dimensionality_reduction(data):
	data = data.drop(['MP', 'G', 'FG', 'FTr', '3PAr', 'ORB%', 'DRB%', 'TRB%', 'STL%', 'WS', 'OWS', 'DWS','WS/48', 'OBPM', '3P'], axis=1)
	return data
	
def RFC_best_params():
	estimators_range = [40, 80, 100, 120, 140, 160, 200, 300]

	max_features_range = ['auto', 'sqrt', 'log2']
	max_features_range = ['auto']
	
	estim = []
	maxF = []
	index_count = 0
	for est in estimators_range:
		RFC.n_estimators = est
		for  max in max_features_range:
			print (est,max)
			RFC.max_features = max
			test_RFC(encoder)
			maxF.append(max)
			index_count = index_count + 1;
		
	rez = pd.DataFrame(index=estimators_range, data={'MaxF': maxF, 'Accuracy': acc, 'F1 measure': f1s})
	rez.plot(kind = 'line')
	plt.show(); 
	print (rez)
	exit();
	
def KNN_best_K():
	neighbors = range(26,30,1)
	ps = range(2,3,1)
	for k in neighbors:
		KNN.n_neighbors = k
		for p in ps:
			KNN.p = p
			print ("k =", KNN.n_neighbors, 'p=',KNN.p)
			test_KNN(encoder)
		
	rez = pd.DataFrame(index=range(26,30,1), data={'Accuracy': acc, 'F1 measure': f1s})
	rez.plot(kind = 'line')
	best = max(rez['Accuracy'])
	index = rez.index[rez['Accuracy'] == best]
	plt.scatter(index, best)
	plt.show(); 

	exit();





def set_squares(data):	
	#data['height'] = data['height'] * data['height']
	#data['weight'] = data['weight'] * data['weight']
	#data['3PA'] = data['3PA'] * data['3PA']
	return data
	
def SVC_best_params():
	kernel_range = ['rbf']
	#test_SVC(encoder)
	#kernel_range = ['linear', 'poly', 'rbf', 'sigmoid']
	
	c_range = np.arange(2.2, 2.5, 0.1);
	
	kernels = []
	cs = []
	sasa =  np.arange(1,4,1)
	for c in c_range:
		SVC.C = c
		for ker in kernel_range:
			SVC.kernel = ker
			print (SVC.C,SVC.kernel)
			test_SVC(encoder)
			kernels.append(ker)
			cs.append(c)
		
	rez = pd.DataFrame(index=sasa, data={'C': cs, 'Kernel': kernels, 'Accuracy': acc, 'F1 measure': f1s})
	rez.plot(kind = 'line')
	plt.show(); 
	print (rez)
	exit();
	
def DTC_best_params():
	#criterion_range = ['gini', 'entropy']
	criterion_range = ['entropy']
	
	#splitter_range = ['best','random']
	splitter_range = ['best']
	
	min_samples_split_range = np.arange(4,15,1)
	#min_samples_split_range = [1,2,3,13]
	max_depth_range = np.arange(8,9,1)
	

	indexes = np.arange(4,15,1)
	for crit in criterion_range:
		DTC.criterion = crit
		for mdep in max_depth_range:
			DTC.max_depth = mdep
			for min in min_samples_split_range:
				DTC.min_samples_leaf = min
				print (DTC.criterion, DTC.min_samples_leaf, DTC.max_depth)
				test_DTC(encoder);
			
	rez = pd.DataFrame(index=indexes, data={'Accuracy': acc, 'F1 measure': f1s})
	rez.plot(kind = 'line')
	plt.show(); 
	print (rez)
	exit();
		
def LDA_best_params():
	solver_range = ['svd', 'lsqr', 'eigen']
	solver_range = ['eigen']
	shrinkage_range = np.arange(0.03, 0.05, 0.002)
	shrinkage_range = np.arange(1, 5, 1)
	indexes = np.arange(1, 5, 1)
	for solv in solver_range:
		LDA.solver = solv;
		for shrink in shrinkage_range:
			LDA.n_components = shrink
			print (LDA.solver,LDA.n_components)
			test_LDA(encoder)
				
	rez = pd.DataFrame(index=indexes, data={'Accuracy': acc, 'F1 measure': f1s})
	rez.plot(kind = 'line')
	plt.show(); 
	print (rez)
	exit();
	
#autoselekcija

#analiza gresak
#autosklearn
#fmeasure ..
#max za seq

def SEQ_best_params():
	print ()
	batch_size_range = np.arange(250, 500, 50)
	#batch_size_range = np.arange(1, 10, 1)
	#epochs_range = np.arange(100, 221, 40)
	epochs_range = [20]
	index_count = 0
	for bs in batch_size_range:
		for ep in epochs_range:
			#print ('iz seq_best_params poslato ep =', ep,'bs =', bs)
			test_SEQ(binarizer, ep, bs);
			index_count = index_count+1
	
	rez = pd.DataFrame(index=np.arange(1,index_count+1,1), data={'Accuracy': acc, 'F1 measure': f1s})
	rez.plot(kind = 'line')
	plt.show(); 
	print (rez)
	exit();
	
	
def plot ():
	index = [40, 80, 100, 120, 140, 160, 200, 300]
	auto_entropy = [75.187,76.034,76.114,75.795,76.059,75.862,75.936,76.157]
	sqrt_entropy = [74.935,75.783,75.850,75.789,75.838,76.108,75.574,76.096]
	log2_entropy = [75.212,75.795,75.703,75.850,75.789,76.040,76.102,76.083]
	
	auto_gini = [74.954,75.285,75.838,75.678,75.884,75.801,76.090,75.948]
	sqrt_gini = [75.138,75.585,75.518,76.151,75.850,75.856,76.004,76.175]
	log2_gini = [74.567,75.525,75.506,75.887,75.813,75.911,75.991,75.924]
	
	data = {'Auto/Entropy': auto_entropy, 'Sqrt/Entropy': sqrt_entropy, 'Log2/Entropy': log2_entropy, 'Auto/Gini': auto_gini, 'Sqrt/Gini': sqrt_gini, 'Log2/Gini': log2_gini}
	
	rez = pd.DataFrame(index=index, data=data)
	rez.plot(kind = 'line')
	plt.show(); 
	print (rez)
	exit();
	
test_seasion = 2017


#plot()
KNN = KNeighborsClassifier()
naive_bayes = GaussianNB()
#naive_bayes = ExtraTreesClassifier()
LDA = LinearDiscriminantAnalysis()
DTC = DecisionTreeClassifier()
RFC = RandomForestClassifier()
SVC = SVC()

SEQ = Sequential()

binarizer = LabelBinarizer()
encoder = LabelEncoder()
scaler = StandardScaler()


acc = []
f1s = []



param = np.arange(100,400,20)

accKNN = []
accDTC = []
accSVC = []

#for current in param:
#print (current)
data = preparing_dataset();
data = remove_by_minutes(data)
data = remove_by_year(data)
data = correct_FG_percentage(data)
data = correct_FT_percentage(data)
data = prepare_totals(data)
data = set_squares(data)
data.reset_index(inplace=True, drop=True)

rookies_data = preparing_rookes()
rookies_data = dimensionality_reduction(rookies_data)



#is_good_to_remove('3PA')
#exit();
	
	
#LDA_best_params()
#DTC_best_params()
#DTC_plot()
#RFC_best_params()
#RFC_plot()
#KNN_best_K()
#SVC_best_params()
#SEQ_best_params()


#ENCODER
#test_KNN(encoder)
#test_LDA(encoder)
#test_DTC(encoder)




data = dimensionality_reduction(data)
test_naive_bayes(encoder)
#test_SVC(encoder)
#test_RFC(encoder)


#BINARIZER
#epochs, batch_size
#test_SEQ(binarizer)



#rez = pd.DataFrame(index=param, data={'KNN': accKNN, 'SVC': accSVC, 'DTC': accDTC})
#rez.plot(kind = 'line')
#
#plt.xlabel('Minutes', fontsize = 14)
#plt.ylabel('Accuracy', fontsize = 14)
#
#plt.show(); 
#print (rez)
#print (rez)

