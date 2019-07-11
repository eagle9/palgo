5. Longest Palindromic Substring
Medium 3848 368 Favorite Share

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
Accepted 591.9K
Submissions 2.1M
Contributor LeetCode

Companies:
0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Amazon | 135 Microsoft | 21 Google | 16 Facebook | 12 Apple | 11 Yahoo | 7 Bloomberg | 6 Adobe | 6 Uber | 3 LinkedIn | 3 Yelp | 2 eBay | 2 Tencent | 2 VMware | 2 Oracle | 2 Mathworks | 2 Wayfair | 2 ByteDance | 2

Similar:
Shortest Palindrome Hard
Palindrome Permutation Easy
Palindrome Pairs Hard
Longest Palindromic Subsequence Medium
Palindromic Substrings Medium
Hint 1
How can we reuse a previously computed palindrome to compute a larger palindrome?
Hint 2
If “aba” is a palindrome, is “xabax” and palindrome? Similarly is “xabay” a palindrome?
Complexity based hint:
Hint 3
If we use brute-force and check whether for every start and end position a substring is a palindrome we have O(n^2) start - end pairs and O(n) palindromic checks. Can we reduce the time for palindromic checks to O(1) by reusing some previous computation.
