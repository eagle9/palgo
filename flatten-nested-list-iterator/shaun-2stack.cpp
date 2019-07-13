
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
/*shaun 2nd round, own idea with 2 stacks, thinking and code, knowing stack will be helpful and used. what if no such hint???
1 stack s1<NestedInteger>,  another stack s2<int>
use stack1 to peel the nestedinteger list, if integer, push to stack2
now stack2 has all integers in the original order
*/
//use example to figure out the details
//Input: [1,[4,[6]]]
// st1:(1, [4..]) , top = [4..]
// st1:(1, 4,[6])    top=[6]
// st1:(1, 4, 6)
//st2: 6 4 1 
//Output: [1,4,6]
//
//accepted first sub, runtime 24ms, faster than 78%, mem less than 12%
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stack<NestedInteger> s1;
        
        for (NestedInteger ni: nestedList) {
            s1.push(ni);
        }
        while (!s1.empty()) {
            NestedInteger ni = s1.top(); s1.pop();
            if (!ni.isInteger()) {
                for (auto x: ni.getList()) s1.push(x);
            }else { //isInteger
                s2.push(ni.getInteger());
            }
        }
        //s1.empty() == true
    }

    int next() {
        int res = s2.top(); s2.pop();
        return res;
    }

    bool hasNext() {
        return !s2.empty();
    }
private:
    stack<int> s2;
    
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

