/**
 * Your object will be instantiated and called as such:
 * ToyFactory* tf = new ToyFactory();
 * Toy* toy = tf->getToy(type);
 * toy->talk();
 */
#include <iostream>
#include <string>
using namespace std;
class Toy {
public:
    virtual void talk() const = 0;
};

class Dog: public Toy {
    // Write your code here
public:
    void talk() const {
        cout << "Wow" << endl;
    }
};

class Cat: public Toy {
    // Write your code here
public:
    void talk() const {
        cout << "Meow" << endl;
    }
};

class ToyFactory {
public:
    /**
     * @param type a string
     * @return Get object of the type
     */
    Toy* getToy(string& type) {
        // Write your code here
        if (type == "Dog") {
            return new Dog();
        }
        else {
            return new Cat();
        }
    }
};
int main() {
 	ToyFactory* tf = new ToyFactory();
	for (string type: {"Dog","Cat"}) {
		Toy* toy = tf->getToy(type);
		toy->talk();
	}
	return 0;
}
