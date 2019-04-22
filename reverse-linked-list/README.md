206. Reverse Linked List
Easy

Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Amazon | 18 Microsoft | 14 Apple | 10 Yandex | 8 Adobe | 7 Facebook | 6 Google | 6 Mathworks | 6 Yahoo | 5 Bloomberg | 4 VMware | 4 Cisco | 4 Baidu | 3 Alibaba | 3 Goldman Sachs | 3 eBay | 2 Uber | 2 TripAdvisor | 2 Oracle | 2

Similar:
Reverse Linked List II Medium
Binary Tree Upside Down Medium
Palindrome Linked List Easy


idea: linhuchong explanation of point/ref and its actual object  and how to draw    
head  n1   n2  NULL
1 n-> 2n ->3n->. 
two moving pointers in sync 
   prev cur
the key is cur.next = prev, but how to implement?
