
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

import pandas as pd
from scipy import stats
from statsmodels.formula.api import ols
from statsmodels.stats.anova import anova_lm
import numpy as np
import seaborn as sns
from statsmodels.stats.multicomp import pairwise_tukeyhsd as tukeyHSD
import os

dataset2=pd.read_csv('Big_mark_sales_train.csv')
type(dataset2['Outlet_Size'].mode().values[0])
dataset2['Outlet_Size']= dataset2['Outlet_Size'].fillna(dataset2['Outlet_Size'].mode().values[0])
dataset2['Item_Weight']=dataset2['Item_Weight'].fillna(dataset2['Item_Weight'].mean())
dataset2['Item_Outlet_Sales']=dataset2['Item_Outlet_Sales'].fillna(dataset2['Item_Outlet_Sales'].mean())
dataset2.isnull().sum()
sns.boxplot(x = dataset2['Item_Visibility'])
sns.distplot(dataset2['Item_Visibility'])
dataset2 = dataset2[np.abs(dataset2.Item_Visibility-dataset2.Item_Visibility.mean()) <= (dataset2.Item_Visibility.std())]

#stanrdize data
dataset_std = dataset2
dataset_std['Item_MRP'] = (dataset2.Item_MRP - np.mean(dataset2.Item_MRP)) / np.std(dataset2.Item_MRP)
dataset_std['Item_Weight'] = (dataset2.Item_Weight - np.mean(dataset2.Item_Weight)) / np.std(dataset2.Item_Weight)
dataset_std['Item_Visibility'] = (dataset2.Item_Visibility - np.mean(dataset2.Item_Visibility)) / np.std(dataset2.Item_Visibility)
dataset_std['Outlet_Establishment_Year'] = (dataset2.Outlet_Establishment_Year - np.mean(dataset2.Outlet_Establishment_Year)) / np.std(dataset2.Outlet_Establishment_Year)
dataset_std['Item_Outlet_Sales'] = (dataset2.Item_Outlet_Sales - np.mean(dataset2.Item_Outlet_Sales)) / np.std(dataset2.Item_Outlet_Sales)


np.mean(dataset_std['Item_MRP'])
np.std(dataset_std['Item_MRP'])
np.mean(dataset_std['Outlet_Establishment_Year'])
np.std(dataset_std['Outlet_Establishment_Year'])

#normalization
dataset_norm =dataset2
dataset_norm['Item_MRP'] = (dataset2.Item_MRP - min(dataset2.Item_MRP))/ (max(dataset2.Item_MRP) - min(dataset2.Item_MRP))
dataset_norm['Item_Weight'] = (dataset2.Item_Weight - min(dataset2.Item_Weight))/ (max(dataset2.Item_Weight) - min(dataset2.Item_Weight))
dataset_norm['Item_Visibility'] = (dataset2.Item_Visibility - min(dataset2.Item_Visibility))/ (max(dataset2.Item_Visibility) - min(dataset2.Item_Visibility))
dataset_norm['Outlet_Establishment_Year'] = (dataset2.Outlet_Establishment_Year - min(dataset2.Outlet_Establishment_Year))/ (max(dataset2.Outlet_Establishment_Year) - min(dataset2.Outlet_Establishment_Year))
dataset_norm['Item_Outlet_Sales'] = (dataset2.Item_Outlet_Sales - min(dataset2.Item_Outlet_Sales))/ (max(dataset2.Item_Outlet_Sales) - min(dataset2.Item_Outlet_Sales))
np.max(dataset_norm['Item_MRP'])
np.min(dataset_norm['Item_MRP'])


#convert categorical to numerical
from sklearn.preprocessing import LabelEncoder, OneHotEncoder
labelencoder_X = LabelEncoder()
dataset_std['Item_Fat_Content'] = labelencoder_X.fit_transform(dataset_std['Item_Fat_Content'])
dataset_std['Item_Type'] = labelencoder_X.fit_transform(dataset_std['Item_Type'])
dataset_std['Outlet_Identifier'] = labelencoder_X.fit_transform(dataset_std['Outlet_Identifier'])
dataset_std['Outlet_Location_Type'] = labelencoder_X.fit_transform(dataset_std['Outlet_Location_Type'])
dataset_std['Outlet_Type'] = labelencoder_X.fit_transform(dataset_std['Outlet_Type'])
dataset_std['Outlet_Size'] = labelencoder_X.fit_transform(dataset_std['Outlet_Size'])
dataset_std.head()

#finding relation b/w target variables and dependent variables
np.corrcoef(dataset_std.Item_Weight,dataset_std.Item_Outlet_Sales)[0,1]
np.corrcoef(dataset2.Item_Weight,dataset2.Item_Outlet_Sales)[0,1]
np.corrcoef(dataset_std.Item_Visibility,dataset_std.Item_Outlet_Sales)[0,1]
np.corrcoef(dataset2.Item_Visibility,dataset2.Item_Outlet_Sales)[0,1]
np.corrcoef(dataset_std.Item_MRP,dataset_std.Item_Outlet_Sales)[0,1]
np.corrcoef(dataset_std.Outlet_Establishment_Year,dataset_std.Item_Outlet_Sales)[0,1]
sns.boxplot(x=dataset_std['Item_Outlet_Sales'] ,y=dataset_std['Item_MRP'])
