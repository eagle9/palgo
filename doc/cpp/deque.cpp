// deque::push_back
/*std::deque tutorial

*/
#include <iostream>
#include <deque>

int main2 ()
{
  std::deque<int> mydeque;
  int myint;

  std::cout << "Please enter some integers (enter 0 to end):\n";

  do {
    std::cin >> myint;
    mydeque.push_back (myint);
  } while (myint);

  std::cout << "mydeque stores " << (int) mydeque.size() << " numbers.\n";
  while (!mydeque.empty()) {
    std::cout << mydeque.front() << std::endl;
    mydeque.pop_front(); //pop_front return void
  }
  return 0;
}

#include <iostream> 
#include <deque> 

using namespace std; 

void showdq(deque <int> g) 
{ 
	deque <int> :: iterator it; 
	for (it = g.begin(); it != g.end(); ++it) 
		cout << '\t' << *it; 
	cout << '\n'; 
} 

int main() 
{ 
	deque <int> gquiz; 
	gquiz.push_back(10); 
	gquiz.push_front(20); 
	gquiz.push_back(30); 
	gquiz.push_front(15); 
  	//15 20 10 30
	cout << "The deque gquiz is : "; 
	showdq(gquiz); 

	cout << "\ngquiz.size() : " << gquiz.size(); 
	cout << "\ngquiz.max_size() : " << gquiz.max_size(); 

	cout << "\ngquiz.at(2) : " << gquiz.at(2); 
	cout << "\ngquiz.front() : " << gquiz.front(); 
	cout << "\ngquiz.back() : " << gquiz.back(); 

	cout << "\ngquiz.pop_front() : "; 
	gquiz.pop_front(); 
	showdq(gquiz); 

	cout << "\ngquiz.pop_back() : "; 
	gquiz.pop_back(); 
	showdq(gquiz); 

	return 0; 
} 
