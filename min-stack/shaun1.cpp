#include <iostream>
#include <stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x < s2.top() ) s2.push(x);
    }
    
    void pop() {
        if (s1.empty()) return;
        int x = top(); s1.pop();
        if (x == s2.top()) s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1, s2;
};
int main() {
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin() <<  "--> Returns -3" << endl;
	minStack.pop();
	cout << minStack.top() << "--> Returns 0" << endl;
	cout << minStack.getMin() <<  "--> Returns -2" << endl;
}
