Lintcode 464
Description
Given an integer array, sort it in ascending order. Use quick sort, merge sort, heap sort or any O(nlogn) algorithm.

Example
Given [3, 2, 1, 4, 5], return [1, 2, 3, 4, 5].

use quicksort 
one index partition vs two index partition
worst case, already sorted, O(n^2)
however, two index improves partition efficiency, reduced the number of swaps
