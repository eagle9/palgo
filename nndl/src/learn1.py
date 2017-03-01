import mnist_loader
import network
training_data, validation_data, test_data = mnist_loader.load_data_wrapper()
len(test_data)
len(training_data)
'''
use stochastic gradient descent to learn from the MNIST training_data over 30 epochs, with a mini-batch size of 10, and a learning rate of η=3.0
choices for the number of epochs of training, the mini-batch size, and the learning rate, ηη. As I mentioned above, these are known as hyper-parameters for our neural network, in order to distinguish them from the parameters (weights and biases) learnt by our learning algorithm
why learning rate is set at 3? 
ans: try learning rate = 0.01 ,then 0.5 ,if the model improves, then keep increasing learning rate. try large value learning rate too. if the model gets worse ,decrease the learning rate. 
'''
#an input layer with 784 neurons, an output layer with 10 neurons, hidden layer 30 neurons
net = network.Network([784,30,10])
net.SGD(training_data, 30, 10, 3.0, test_data=test_data)
'''
Epoch 0: 8985 / 10000
Epoch 1: 9112 / 10000
...
Epoch 27: 9498 / 10000
Epoch 28: 9507 / 10000
Epoch 29: 9505 / 10000

the trained network gives us a classification rate of about 9507 percent - 95.07 percent at its peak ("Epoch 28")
''' 

'''
#Let's rerun the above experiment, changing the number of hidden neurons to 100 0
'''
net = network.Network([784, 100, 10])
net.SGD(training_data, 30, 10, 3.0, test_data=test_data)
'''
Epoch 0: 4277 / 10000
Epoch 1: 5887 / 10000
Epoch 26: 8732 / 10000
Epoch 27: 8731 / 10000
Epoch 28: 8720 / 10000
Epoch 29: 8724 / 10000
no improvement after increase number of neurons at hidden layer. Michael Nielsen said doing so the recognition rate increased to 96%. However it got worse in my test run.

'''


