import pandas as pd
from sklearn import tree
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report
from micromlgen import port

# Load dataset
df = pd.read_csv('dataset.csv')
X = df.drop('House', axis=1)
y = df['House']

# Encode target labels
encoder = LabelEncoder()
y_encoded = encoder.fit_transform(y)

# Train/test split
X_train, X_test, y_train, y_test = train_test_split(X, y_encoded, test_size=0.2)

# Train model
clf = tree.DecisionTreeClassifier(max_depth=4)
clf.fit(X_train, y_train)

# Evaluate
print(classification_report(y_test, clf.predict(X_test)))

# Export to C++
c_code = port(clf, classmap=encoder.classes_)
with open('../sorting_hat_ESP32/sorting_model.h', 'w') as f:
    f.write(c_code)
