#  DATASET
# https://archive.ics.uci.edu/ml/datasets/combined+cycle+power+plant#
from pyspark.ml.evaluation import RegressionEvaluator
from pyspark.sql import SparkSession

path = "PowerPlant.csv"

sparkSession = SparkSession.builder.appName('tempPredict').getOrCreate()
input_df = sparkSession.read.csv(path, header = True, inferSchema = True)

input_df.printSchema()
cols = input_df.columns
input_df = input_df.toPandas()

df_spark = sparkSession.createDataFrame(input_df)

from pyspark.ml.feature import VectorAssembler
vectorAssembler = VectorAssembler(inputCols = ['AT','V','AP','RH'], outputCol = 'features')
vector_df = vectorAssembler.transform(df_spark)
vector_df = vector_df.select(['features', 'PE'])


splits = vector_df.randomSplit([0.7, 0.3])
train_df = splits[0]
test_df = splits[1]

## Linear regression portion
from pyspark.ml.regression import LinearRegression
lr = LinearRegression(featuresCol = 'features', labelCol='PE', maxIter=10, regParam=0.3, elasticNetParam=0.8)
lr_model = lr.fit(train_df)
print("Coefficients: " + str(lr_model.coefficients))
print("Intercept: " + str(lr_model.intercept))

trainingSummary = lr_model.summary
print("RMSE: %f" % trainingSummary.rootMeanSquaredError)
print("r2: %f" % trainingSummary.r2)

train_df.describe().show()

lr_predictions = lr_model.transform(test_df)
lr_predictions.select("prediction","PE","features").show(5)
lr_evaluator = RegressionEvaluator(predictionCol="prediction", labelCol="PE",metricName="r2")
print("R Squared (R2) on test data = %g" % lr_evaluator.evaluate(lr_predictions))

## DecisionTreeRegressor portion
from pyspark.ml.regression import DecisionTreeRegressor
dt = DecisionTreeRegressor(featuresCol ='features', labelCol = 'PE')
dt_model = dt.fit(train_df)
dt_predictions = dt_model.transform(test_df)
dt_evaluator = RegressionEvaluator(
    labelCol="PE", predictionCol="prediction", metricName="rmse")
rmse = dt_evaluator.evaluate(dt_predictions)
print("DecisionTreeRegressor Root Mean Squared Error (RMSE) on test data = %g" % rmse)