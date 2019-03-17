// queue::push/pop
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue

int main () {
  std::queue<int> myqueue;
  int myint;

  std::cout << "Please enter some integers (enter 0 to end):\n";
  int a = 1;
  myqueue.push(a); //a is passed by ref, but queue creates new element 
  a = 2;
  myqueue.push(a);
  a = 3;
  myqueue.push(a);
  //event a is changed, queue elements: 1 2 3


  std::cout << "myqueue contains: ";
  while (!myqueue.empty()){
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  std::cout << '\n';

  return 0;
}
