// istringstream constructors.
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
using namespace std;
int main () {

  string stringvalues = "125 320 512 750 333";
  istringstream iss(stringvalues);

  for (int n=0; n<5; n++) {
    int val;
    iss >> val; //val << iss not working
    cout << val << '\n';
  }
  //what if we don't know the number of splits? 
  istringstream is2(stringvalues);
  int number;
  cout << "split string with space with while loop:" << endl;
  while ( is2 >> number) {
	cout << number << endl;
  }
  string input = "abc,def,ghi";
  istringstream ss(input);
  string token;
  cout << "split with comma:" << endl;
  while(getline(ss, token, ',')) {
    cout << token << '\n';
  }
  return 0;
}
