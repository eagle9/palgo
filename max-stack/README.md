716. Max Stack
Easy 350 57 Favorite Share

Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.

Accepted 26.5K
Submissions 65.9K

Contributor fallcreek
0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
LinkedIn | 15 Lyft | 8 Amazon | 6
1 year ~ 2 years
Google |2

Topic: Design, Stack

Similar:
Min Stack Easy
