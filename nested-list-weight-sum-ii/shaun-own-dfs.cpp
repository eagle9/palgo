/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/*
shaun's own idea and code accepted first sub. 
tested my code with example, corrected 1 bug without submission
great experience!

cutting idea angle:
find depth first
then dfs(list, weight) similar to version 1 to get the sum

getDepth(list0,1) //find the maxDepth using dfs
return dfs(list0, maxDepth) //dfs to find weighted sum

runtime 4ms, faster than 80%, mem less than 11%

*/
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        getDepth(nestedList,1);
        return dfs(nestedList, maxDepth);
    }
private:
    int dfs(vector<NestedInteger>& nestedList, int weight) {
        int sum = 0;
        for (auto e: nestedList) {
            if (e.isInteger()) sum += e.getInteger() * weight;
            else {
                sum += dfs(e.getList(), weight-1);
            }
        }
        return sum;
    }
    int maxDepth = 0;
    void getDepth(vector<NestedInteger>& nestedList, int depth) {
        for (auto e: nestedList) {
            //depth++;
            if (e.isInteger()) maxDepth = max(maxDepth, depth);
            else {
                getDepth(e.getList(), depth+1);
            }
        }
    }
    /*
    getDepth( [1,[4,[6]]], 1)
    depth = 1
    for {
        
        1:  maxDepth = 1 
        getDepth([4,[6]], 2)
            depth = 2
            4: maxDepth = 2
            getDepth([6], 3)
                depth = 3
                6: maxDepth = 3
    }
    
    1*3 + 4*2 + 6*1
    =3 + 8 + 6 = 17
    */

};
