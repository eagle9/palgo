307. Range Sum Query - Mutable
Medium
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
Topic: Binary Indexed Tree, Segment Tree
Similar: Range Sum Query - Immutable
Range Sum Query 2D - Mutable

classical use of Binary indexed tree
parent child relationship:  index 0 is dummy node that does not store any array element, init as 0
each node has an index,   dummpy node index 0 will be the parent.  node with index i, take it binary representation, flip the last 1 bit, you get another smaller index, which is the parent. 
bi tree is used to store prefix sum of the array.  How ???

