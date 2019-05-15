#include <iostream>
#define NAME_SIZE 32 
using namespace std;
class Person {
	int id;// all members are private by default
	char name[NAME_SIZE];
public:
	virtual void aboutMe() {
		cout << "I am a person." << endl;
	}
	virtual bool addCourse(string s) = 0;
	//~Person() { cout << "Delete a person." << endl;}
	virtual ~Person() { cout << "Delete a person." << endl;}
};

class Student : public Person {
public:
	void aboutMe() {
		cout << "I am a student." << endl;
	}

	bool addCourse(string s) {
		cout << "Added course " << s << " to student." << endl;
		return true;
	}
	~Student() { cout << "Delete a student." << endl; }
};

int main() {
	//Person p0; //Person is abstract type and can not be instantiated
	Person * p = new Student();
	p->aboutMe(); // prints "I am a student."
	p->addCourse("History");
	
	Person* p2 = new Student();
	delete p2;
	
}

