from sklearn import svm
from sklearn import datasets
import random
#random.seed(15032015)

iris = datasets.load_iris()
X, y = iris.data, iris.target
ind = [i for i in range(150)]
random.shuffle(ind)
X=X[ind]
y=y[ind]
train_x = X[0:100]
test_x = X[100:]

train_y = y[0:100]
test_y = y[100:]

clf = svm.SVC()
clf.fit(train_x, train_y)
p = list(clf.predict(test_y))

