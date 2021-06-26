// 'Hello World!' program 
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
struct MyStruct {
    int key;
    string stringValue;
    MyStruct(int k, const std::string& s) : key(k), stringValue(s) {}

    bool operator > (const MyStruct& str) const {
        return (key > str.key);
    }
};
int main() {
	string temp = "what a wonderful day!";
  	std::cout << temp << std::endl;
	temp[0] = 'W';
	cout << temp << endl;

	vector< MyStruct > values;
	values.push_back(MyStruct(4, "test"));
	values.push_back(MyStruct(3, "a"));
	values.push_back(MyStruct(2, "is"));
	values.push_back(MyStruct(1, "this"));

	sort( values.begin( ), values.end( ), [ ]( const auto& lhs, const auto& rhs ) { return lhs.key < rhs.key; });

  	return 0;
}
