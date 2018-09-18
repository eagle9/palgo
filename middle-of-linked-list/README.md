228. middle of Linked List
Find the middle node of a linked list.

Example
Given 1->2->3, return the node with value 2.
Given 1->2->3->4->5, return node with value 3.

Given 1->2, return the node with value 1.

Challenge
If the linked list is in a data stream, can you find the middle without iterating the linked list again?
Not quite understand data stream case.

jiadai and jz have the same idea:
use two pointer, one slow, one fast, however let fast started one step ahead 
slow ->1
fast ->2
first iter, slow -> 2, fast -> 3.next = null, return slow->
iter1: slow -> 2, fast-> 4
iter2: slow -> 3, fast-> 5.next = null, return 3
instead of slow & fast start from head, let fast 1 step ahead, try with simple examples
it is key to determine the good start for slow and fast pointer
since fast is 1 step ahead, use fast's null test as loop exit condition
