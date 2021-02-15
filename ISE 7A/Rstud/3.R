library(arules)
library(arulesViz)

data("Groceries")
inspect(Groceries[1:10])

#bar graph showing the top 10 frequent items
itemFrequencyPlot(Groceries,topN=10,type="absolute")

#generate and display frequent itemsets in decreasing order of support
itemSets <- apriori(Groceries, parameter=list(minlen=1, maxlen=10,sup=0.02, target="frequent itemsets"))
inspect(sort(itemSets,by="support"))

#generate and display strong rules in decreasing order of confidence
itemRules <- apriori(Groceries, parameter=list(minlen=1, maxlen=10, sup=0.02, conf=0.4, target="rules"))
inspect(sort(itemRules,by="confidence"))

#graph showing the strong association rules
plot(itemRules, method="graph")
