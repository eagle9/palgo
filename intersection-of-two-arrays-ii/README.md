350. Intersection of Two Arrays II
Easy

Given two arrays, write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

1.What if the given array is already sorted? How would you optimize your algorithm?
2.What if nums1's size is small compared to nums2's size? Which algorithm is better?
3.What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
我可以肯定的是1和2
1.already sorted, use two pointers
2.store nums1 into hashmap, then iterate nums2 to check if each number is in nums1 or not
3.因为nums1是可以放到内存的，所以就把nums1放到hashmap里，然后从disk分多次取出nums2，判断一下就好了

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Facebook | 11 Google | 4 Amazon | 3 Bloomberg | 2 Uber | 2

Similar:
Intersection of Two Arrays Easy
Find Common Characters Easy

Topic: Hash Table, Two Pointers, Binary Search, Sort
