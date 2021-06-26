# 460. K Closest Numbers In Sorted Array

Difficulty: Medium

http://lintcode.com/en/problem/k-closest-numbers-in-sorted-array/

Given a target number, a non-negative integer k and an integer array A sorted in ascending order, find the k closest numbers to target in A, sorted in ascending order by the difference between the number and target. Otherwise, sorted in ascending order by number if the difference is same.

**Example**  
Given A = [1, 2, 3], target = 2 and k = 3, return [2, 1, 3].

Given A = [1, 4, 6, 8], target = 3 and k = 3, return [4, 1, 6].

start =0, end = 3
mid = 1
A[mid] = 4 >= target
end = 1

now loop exit start+1 = end: start,end = 0,1
index = 1
left,right = 0,1
result = [ A[right] ] = [4]
   right = 2
   A[left] = 1, A[right] = 6, A[left] closer to 3
      result=[4,1], left = -1
left < 0 now, result = [4,1,6], right = 3
   loop for 3 times now, exit, all k numbers are found.
