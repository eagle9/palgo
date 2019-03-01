251. Flatten 2D Vector
Medium

Design and implement an iterator to flatten a 2d vector. It should support the following operations: next and hasNext.

Example:
Vector2D iterator = new Vector2D([[1,2],[3],[4]]);
iterator.next(); // return 1
iterator.next(); // return 2
iterator.next(); // return 3
iterator.hasNext(); // return true
iterator.hasNext(); // return true
iterator.next(); // return 4
iterator.hasNext(); // return false
 
Notes:

Please remember to RESET your class variables declared in Vector2D, as static/class variables are persisted across multiple test cases. Please see here for more details.
You may assume that next() call will always be valid, that is, there will be at least a next element in the 2d vector when next() is called.
 
Follow up:

As an added challenge, try to code it using only iterators in C++ or iterators in Java.

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Google | 3 LinkedIn | 2 Uber | 2 Yelp | 2 Twitter | LeetCode Zenefits |

Topic: Design

Similar:
Binary Search Tree Iterator Medium
Zigzag Iterator Medium
Peeking Iterator Medium
Flatten Nested List Iterator Medium

Hint 1:
How many variables do you need to keep track?

Hint 2:
Two variables is all you need. Try with x and y.

Hint 3:
Beware of empty rows. It could be the first few rows.

Hint 4:
To write correct code, think about the invariant to maintain. What is it?

Hint 5:
The invariant is x and y must always point to a valid point in the 2d vector. Should you maintain your invariant ahead of time or right when you need it?

Hint 6:
Not sure? Think about how you would implement hasNext(). Which is more complex?

Hint 7:
Common logic in two different places should be refactored into a common method.
