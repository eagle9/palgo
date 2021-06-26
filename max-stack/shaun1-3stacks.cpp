#include <stack>
#include <iostream>
using namespace std;
class MaxStack {
private: 
    stack<int> s1, s2; //s1 regular store, s2 stores the max
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x >= s2.top()) s2.push(x);
    }
    
    int pop() {
        int res = s1.top();
        s1.pop();
        if (s2.top() == res) s2.pop();
        return res;
        
    }
    
    int top() {
        return s1.top();
    }
    
    int peekMax() {
        return s2.top();
    }
    
    int popMax() {
        int res = s2.top();
        s2.pop();
        stack<int> temp;
        while (s1.top() != res) {
            int x  = s1.top();
            temp.push(x);
            s1.pop();
        }
        //now s1.top = res, which is the first max
        s1.pop();
        //now push all elements in temp back into s1
        while (!temp.empty()) {
            s1.push(temp.top());
            temp.pop();
        }
        return res;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
int main() {
	cout << "hello" << endl;
	MaxStack st;
	st.push(5);
	st.push(1);
	st.push(5);
	cout << st.top() << " 5" << endl; //-> 5
	cout << st.popMax() <<  " 5" << endl; // -> 5
	cout << st.top() << " 1" << endl; // -> 1
	cout << st.peekMax() << " 5" << endl; //-> 5
	cout << st.pop() << " 1" << endl; //-> 1
	cout << st.top() << " 5" << endl; //-> 5
}
