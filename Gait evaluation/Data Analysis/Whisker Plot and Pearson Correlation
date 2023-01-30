import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


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


df = pd.concat ([df1, df2, df3, df4, df5, df6, df7, df8, df9, df10])

df = df.dropna() #remove linhas com valores ausentes
df = df.drop_duplicates() #remove linhas duplicadas

fig, ax = plt.subplots(figsize=(10, 5))

# get the statistics from the boxplot
stats = df.groupby(['Marcha'])['wy'].describe()

print(stats)

#draw Whisker Plot
"""
#create the boxplot
sns.boxplot(x="Marcha", y="wy", data=df, ax=ax)


ax.set_xticklabels(['Trípode', 'Onda' , 'Metacronal'])
plt.xlabel(" \n Marcha")
plt.ylabel("Velocidade Angular Wy (º/s)")
plt.ylim(-40, 40)
plt.show()

"""
#draw Pearson Correlation
corr = df.corr(method ='pearson')

fig, ax = plt.subplots()
im = ax.imshow(corr, cmap='coolwarm', interpolation='nearest')
plt.imshow(corr, cmap='coolwarm', interpolation='nearest')
ax.set_xticklabels(['','Marcha', 'Tempo','Velocidade Linear', 'Velocidade Angular (X)', 'Velocidade Angular (Y)', 'Roll', 'Pitch'], rotation='vertical',fontsize=15)
ax.set_yticklabels(['','Marcha', 'Tempo', 'Velocidade Linear', 'Velocidade Angular (X)', 'Velocidade Angular (Y)', 'Roll', 'Pitch'], fontsize=15)
cbar = plt.colorbar(im)
im.set_clim(-0.6, 1)

plt.show()




