Description
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

1.The input strings only contain lower case letters.
2.The length of both given strings is in range [1, 10,000].

Example
Example 1:

Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False

Diff: medium
Com: MS

sliding window:
Time: O(L1+26*(L2-L1)) 
Space: O(1). Constant space is used.

sliding window optimized:
Time: O(L1 + (L2 - L1))
Space: O(1)
