#include <iostream> 
#include <list> 
#include <iterator> 
using namespace std; 
/*
c++ stl list tutorial, doublely linked list
iterator
push_back, push_front, pop_back,pop_front
splice, emplace, sort, reverse
*/

//function for printing the elements in a list 
void showlist(list <int> g) 
{ 
    //list<int>::iterator it;  //declare it as auto for type inference
    for(auto it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 
  
int main() 
{ 
  
    list <int> gqlist1, gqlist2; 
  
  
    for (int i = 0; i < 10; ++i) 
    { 
        gqlist1.push_back(i * 2); 
        gqlist2.push_front(i * 3); 
    } 
    cout << "\nList 1 (gqlist1) is : "; 
    showlist(gqlist1); 
    //second to last
    list<int>::iterator it = gqlist1.end();
    //it -= 2;  //not working
    //it--;it--; //working
    advance(it,-2); //working
    //move it front of the list
    gqlist1.splice(gqlist1.begin(), gqlist1,it);
    cout << "\nafter move second to last to front, List 1 (gqlist1) is : "; 
    showlist(gqlist1); 

    gqlist1.pop_back();
    cout << "\nafter pop_back, List 1 (gqlist1) is : "; 
    showlist(gqlist1); 

    gqlist1.emplace(gqlist1.begin(), 55);
    cout << "\nafter enter 55 at begining, List 1 (gqlist1) is : "; 
    showlist(gqlist1); 

    cout << "\nList 2 (gqlist2) is : "; 
    showlist(gqlist2); 

    cout << "\ngqlist1.front() : " << gqlist1.front(); 
    //.back() returns A reference to the last element in the list.
    cout << "\ngqlist1.back() : " << gqlist1.back(); 
  
    cout << "\ngqlist1.pop_front() : "; 
    gqlist1.pop_front(); 
    showlist(gqlist1); 
  
    cout << "\ngqlist2.pop_back() : "; 
    gqlist2.pop_back(); 
    showlist(gqlist2); 
  
    cout << "\ngqlist1.reverse() : "; 
    gqlist1.reverse(); 
    showlist(gqlist1); 
  
    cout << "\ngqlist2.sort(): "; 
    gqlist2.sort(); 
    showlist(gqlist2); 
  
    return 0; 
  
} 

