library(rpart)
library(rpart.plot)
library(e1071)
library(party)
library(caret)

data <- iris
index <- sample(2,nrow(data),replace=TRUE,p=c(0.7,0.3))
trainData <- data[index==1,]
testdata  <- data[index==2,]

#Y vs X
features <- Species ~ Sepal.Length + Sepal.Width + Petal.Length + Petal.Width

#decision tree

tree1 <- rpart(features,trainData,method="class")
rpart.plot(tree1)

tree2 <- ctree(features,trainData)
plot(tree2)

#Dtree prediction
res1 <- predict(tree2,testdata)
confusionMatrix(res1,testdata$Species)

#Naive bayes
mode1 <- naiveBayes(features,trainData)
print(mode1)

#Naive bayes Prediction
res2 <- predict(mode1,testdata)
confusionMatrix(res2,testdata$Species)