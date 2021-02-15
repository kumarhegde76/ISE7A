import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
data=pd.read_csv("Iris.csv")
data.head()
data.info()
data.isna().sum()

data["SepalLengthCm"].fillna(data["SepalLengthCm"].mean(),inplace=True)
#Removing duplicates
data.sort_values("SepalLengthCm",inplace=True)
data.drop_duplicates(subset="SepalLengthCm",keep=False,inplace=True)
data.head()

data['Species'].value_counts()
tmp = data.drop('Id', axis=1)
g = sns.pairplot(tmp, hue='Species', markers='+')
plt.show()
g = sns.countplot(x='Species',data=data)
plt.show()
g = sns.violinplot(y='Species', x='SepalWidthCm', data=data, inner='quartile')
plt.show()
g = sns.violinplot(y='Species', x='PetalLengthCm', data=data, inner='quartile')
plt.show()
g = sns.violinplot(y='Species', x='PetalWidthCm', data=data, inner='quartile')
plt.show()

# Aggregation
data.groupby(['Species']).mean()
