import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split

# Load the data from the CSV file into a pandas dataframe
df = pd.read_csv('gait_data.csv')

# Split the data into features (X) and labels (y)
X = df[['velocity', 'orientation', 'angular_velocity']]
y = df['gait']

# Split the data into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

# Train the KNN model on the training data
model = KNeighborsClassifier(n_neighbors=5)
model.fit(X_train, y_train)

# Test the model on the test data
accuracy = model.score(X_test, y_test)
print(f'Model accuracy: {accuracy:.2f}')
