install.packages("fpc")
library(fpc)
data<-iris[-5]
set.seed(200)
d <- dbscan(data , eps=0.45 , MinPts = 5)
d
d$cluster
table(d$cluster , iris$Species)
plot(d , data , main="DBScan")
plot(d, data , main = "Petal Width VS Sepal length")

