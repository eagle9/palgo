567. Permutation in String
Medium 699 37 Favorite Share

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
 
Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

Facebook | 9 Google | 2

Minimum Window Substring Hard
Find All Anagrams in a String Easy

hint 1. 
Obviously, brute force will result in TLE. Think of something else.
hint 2. 
How will you check whether one string is a permutation of another string?
hint 3.
One way is to sort the string and then compare. But, Is there a better way?
If one string is a permutation of another string then they must one common metric. What is that?
Both strings must have same character frequencies, if one is permutation of another. Which data structure should be used to store frequencies?
What about hash table? An array of size 26?


lintcode
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
