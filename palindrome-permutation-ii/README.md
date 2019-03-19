267. Palindrome Permutation II
Medium

Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

Example 1:
Input: "aabb"
Output: ["abba", "baab"]

Example 2:
Input: "abc"
Output: []
0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

Companies: Uber | 2

Similar:
Next Permutation Medium
Permutations II Medium
Palindrome Permutation Easy

Hint 1:
If a palindromic permutation exists, we just need to generate the first half of the string.

Hint 2:
To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.

Topic: Backtracking

idea:
generate P(n,n), check if each permu string palindrome or not
optimize, if palindrome permutation exists, then do permu with dfs
if is_palindrome(str) res.push_back()
optimize take half of str, do full permu
