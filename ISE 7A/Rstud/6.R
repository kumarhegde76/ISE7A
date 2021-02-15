install.packages("randomForest")
library(party)
library(randomForest)
data <-iris
data
output.forest <- randomForest(Species ~ Sepal.Length + Sepal.Width + Petal.Length + Petal.Width , data=iris)
print(output.forest)
plot(output.forest)