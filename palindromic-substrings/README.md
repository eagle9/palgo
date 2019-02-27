647. Palindromic Substrings
Medium

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 
Note:

The input string length won't exceed 1000.

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Companies: Pure Storage | 15 Amazon | 4 Google | 3 Facebook | 3 Coursera | 3 Microsoft | 2

Similar:
Longest Palindromic Substring Medium
Longest Palindromic Subsequence Medium
Palindromic Substrings Medium

Hint 1:
How can we reuse a previously computed palindrome to compute a larger palindrome?

Hint 2:
If “aba” is a palindrome, is “xabax” and palindrome? Similarly is “xabay” a palindrome?

Hint 3:
Complexity based hint:
If we use brute-force and check whether for every start and end position a substring is a palindrome we have O(n^2) start - end pairs and O(n) palindromic checks. Can we reduce the time for palindromic checks to O(1) by reusing some previous computation?


Topic: String, Dynamic Programming

hf problem, with many similar, must do well
