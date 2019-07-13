/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
//shaun code from grandyang idea, accepted after fixing 2 errors
//runtime 24ms, faster than 79%, mem less than 26%
//key to understand next() is called with hasNext()
//data structure will be used to support the iterator, read the problem and given info fully
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        //for (auto it = nestedList.rbegin(); it != nestedList.rend(); it++) {
        for (int i = nestedList.size()-1; i >= 0; --i) {
            s.push(nestedList[i]);
        }
    }

    //next called when hasNext returns true
    int next() {
        auto e = s.top(); s.pop();
        return e.getInteger();
    }

    bool hasNext() {
        //look for valid integer from the stack
        while (!s.empty()){
            auto e = s.top();
            if (e.isInteger()) return true;
            //now e is a list/vector
            //replace e with its elements
            s.pop();
            vector<NestedInteger> list1 = e.getList();
            for (int i = list1.size()-1; i >=0; --i) {
                s.push(list1[i]);
            }
        }
        //now stack is empty and still not return or find a valid integer
        return false;
    }
    
private:
    stack<NestedInteger> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
