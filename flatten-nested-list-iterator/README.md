341. Flatten Nested List Iterator
Medium 998 418 Favorite Share

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,4,6].

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Amazon | 8 Uber | 6 Facebook | 4 Apple | 4 Twitter | 4 Google | 4 LinkedIn | 4 Airbnb | 4

Topic:
Stack, Design

Flatten 2D Vector Medium
Zigzag Iterator Medium
Mini Parser Medium
Array Nesting Medium


idea
Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Input: [1,[4,[6]]]
Output: [1,4,6]


vector<NestInteger>& nestedList
use stack??? i feel like we need to use queue!!!!
stack first in, last out, last in, first out

how to implement next? use data strecture  yes ---> stack, queue is more natural to me
for (auto e: nestedList) {
    while (!e.isInteger()) {
        auto list = e.getList();
        for (auto ee: list) {
            stack.push(ee)
        }
    }
    //now e.isInteger() true
    output e.getInteger()
    
}
draw a picture to show how a nested element is replaced with its elements
gather info and insights from problem description:
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
