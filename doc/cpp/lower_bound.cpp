// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector
using namespace std;
int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  vector<int>::iterator low,up;

  low=lower_bound (v.begin(), v.end(), 20);
  cout << "lower_bound with 20 at position " << (low- v.begin()) << " " << *low << endl; //v[low] error

  auto low2=lower_bound (v.begin(), v.end(), 21);
  cout << "lower_bound with 21 at position " << (low2- v.begin()) << " " << *low2 << endl; //v[low] error

  up= upper_bound (v.begin(), v.end(), 30);
  cout << "upper_bound with 30 at position " << (up - v.begin()) <<" "<< *up << endl;

  auto up2= upper_bound (v.begin(), v.end(), 20);
  cout << "upper_bound with 20 at position " << (up2 - v.begin()) <<" "<< *up2 << endl;
  return 0;
}

/*
clang version 7.0.0-3~ubuntu0.18.04.1 (tags/RELEASE_700/final)
lower_bound with 20 at position 3 20
lower_bound with 21 at position 6 30
upper_bound with 30 at position 8 0
upper_bound with 20 at position 6 30
*/
