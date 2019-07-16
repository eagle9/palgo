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

/*shaun own idea and code, accepted after 1 bug fix(dfs(e,depth+1)) ===> dfs(e.getList(), depth+1)
found out lt has the same idea and similar code

i am glad that i came up dfs(nestList, depth) function structure
runtime 0ms, faster than 100%, mem less than 18%
*/
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
    }
private:
    int dfs(vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;
        for (auto e: nestedList) {
            if (e.isInteger()) sum += e.getInteger() * depth;
            else {
                sum += dfs(e.getList(), depth+1); //bug, dfs(e, depth+1) ---> dfs(e.getList(), depth+1)
            }
        }
        return sum;
    }
};

/*
shaun testing
dfs ([1, [4, [6]]], 1) = 27
 sum = 0
 sum += 1*1 = 1
 sum += dfs([4,[6]], 2) = 26
     sum = 0
     sum += 4* 2 = 8
     sum += dfs([6], 3) = 18 ---> sum =8+18 = 26
         sum = 0
         sum += 6* 3 = 18
         return sum
         
Complexity Analysis

The algorithm takes O(N)O(N) time, where NN is the total number of nested elements in the input list. For example, the list [ [[[[1]]]], 2 ] contains 44 nested lists and 22 nested integers (11 and 22), so N=6N=6.

In terms of space, at most O(D)O(D) recursive calls are placed on the stack, where DD is the maximum level of nesting in the input. For example, D=2D=2 for the input [[1,1],2,[1,1]], and D=3D=3 for the input [1,[4,[6]]].

*/
