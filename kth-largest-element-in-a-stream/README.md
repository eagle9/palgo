703. Kth Largest Element in a Stream
Easy 337 158 Favorite Share

Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element in the stream.

Example:
int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4, [2 3 4 5 8]
kthLargest.add(5);   // returns 5, [3 4 5 5 8]
kthLargest.add(10);  // returns 5, [4 5 5 8 10]  
kthLargest.add(9);   // returns 8, [5 5 8 9 10]
kthLargest.add(4);   // returns 8, [4 5 8 9] 
Note: 
You may assume that nums' length ≥ k-1 and k ≥ 1.

Accepted 37,131
Submissions 79,583

Contributor LeetCode
0 ~ 6 months
Amazon |10
6 months ~ 1 year1 year ~ 2 years
Facebook | 6 eBay | 3 Google | 2

Topic: Heap

Similar:
Kth Largest Element in an Array Medium
