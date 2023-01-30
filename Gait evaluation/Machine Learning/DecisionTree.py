#There are several machine learning algorithms that you could use to classify the best gait for a given terrain based on velocity, orientation, and angular velocity. One simple and effective option is to use a decision tree.

#A decision tree is a supervised learning algorithm that can be used for classification tasks. It works by creating a tree-like model of decisions based on the features of your data. At each node in the tree, the algorithm makes a decision based on the value of a particular feature. The final decision at the leaf nodes of the tree determines the class label for the input data.

#Here is an example of how you could use a decision tree to classify the best gait for a given terrain in Python:
import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt

# Import excel data

df1 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste1tr.xlsx")
df2 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste2tr.xlsx")
df3 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste3tr.xlsx")
df4 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste4tr.xlsx")
df5 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste5tr.xlsx")
df6 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste6tr.xlsx")
df7 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste7tr.xlsx")
df8 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste8tr.xlsx")
df9 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste9tr.xlsx")
df10 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste10tr.xlsx")
df11 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste1On.xlsx")
df12 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste2On.xlsx")
df13 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste3On.xlsx")
df14 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste4On.xlsx")
df15 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste5On.xlsx")
df16 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste6On.xlsx")
df17 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste7On.xlsx")
df18 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste8On.xlsx")
df19 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste9On.xlsx")
df20 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste10On.xlsx")
df21 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste1Met.xlsx")
df22 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste2Met.xlsx")
df23 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste3Met.xlsx")
df24 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste4Met.xlsx")
df25 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste5Met.xlsx")
df26 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste6Met.xlsx")
df27 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste7Met.xlsx")
df28 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste8Met.xlsx")
df29 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste9Met.xlsx")
df30 = pd.read_excel("C:/Users/Diogo Cordeiro/Desktop/ArduinoTestesMachine/TestesFin/Teste10Met.xlsx")

df = pd.concat ([df1, df2, df3, df4, df5, df6, df7, df8, df9, df10, df11, df12, df13, df14,df15, df16, df17, df18, df19, df20, df21, df22,df23,df24,df25])

df = df.dropna() #remove linhas com valores ausentes
df = df.drop_duplicates() #remove linhas duplicadas


X = df[['tempo','velocidade', 'wx', 'wy','X','Y']]
y = df['Marcha']

# Split the data into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

# Train the decision tree model on the training data
model = DecisionTreeClassifier()
model.fit(X_train, y_train)

# Test the model on the test data
accuracy = model.score(X_test, y_test)
print(f'Model accuracy: {accuracy:.2f}')

# display decision tree
from sklearn.tree import plot_tree
plt.figure(figsize=(20,20))
plot_tree(model, filled=True, fontsize=10)
plt.show()

#This code will train a decision tree model on the gait data and then evaluate its performance on a separate test set. You can then use the trained model to predict the best gait for a given terrain based on its velocity, orientation, and angular velocity.

#You can also try other classification algorithms, such as k-nearest neighbors (KNN) or support vector machines (SVM), to see which one performs best on your data.