148. Sort List
Medium
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5

Topic: Linked List, Sort

Similar: 
Merge two sorted lists(easy)
Sort Colors (medium)
Insertion Sort List(medium)

Idea: data stored in a linked list making it hard to use quick sort. 
but merge sort works. use two pointers to divide the list into two half lists. 
The merge the two smaller list

