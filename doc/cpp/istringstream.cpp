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
  return 0;
}
