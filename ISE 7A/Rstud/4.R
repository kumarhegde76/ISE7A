library("rJava")
library("rCBA")
data <-iris
train <- sapply(iris,as.factor)
train <- data.frame(train, check.names=FALSE)
txns <- as(train,"transactions")
rules = rCBA::fpgrowth(txns, support=0.03, confidence=0.03, maxLength=1, consequent="Species", parallel=FALSE)
inspect(rules)
