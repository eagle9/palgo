"""
mnist_svm
~~~~~~~~~

A classifier program for recognizing handwritten digits from the MNIST
data set, using an SVM classifier."""

#### Libraries
# My libraries
import mnist_loader 

# Third-party libraries
from sklearn import svm

def svm_baseline():
    training_data, validation_data, test_data = mnist_loader.load_data()
    # train
    #http://peekaboo-vision.blogspot.de/2010/09/mnist-for-ever.html
    gamma =  0.00728932024638  #kernel coefficient
    C = 2.82842712475   #penalty parameter  of error term

    clf = svm.SVC(C=C,gamma=gamma)
    clf.fit(training_data[0], training_data[1])
    # test
    predictions = [int(a) for a in clf.predict(test_data[0])]
    num_correct = sum(int(a == y) for a, y in zip(predictions, test_data[1]))
    print "Baseline classifier using an SVM."
    print "%s of %s values correct." % (num_correct, len(test_data[1]))

if __name__ == "__main__":
    svm_baseline()
'''
	svm.SVC()
	Baseline classifier using an SVM.
	9435 of 10000 values correct
	svm.SVC(C=C,gamma=gamma)
	Baseline classifier using an SVM.
	9780 of 10000 values correct.
'''
    
