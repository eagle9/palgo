336. Palindrome Pairs
Hard
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Input: ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]] 
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]

Example 2:
Input: ["bat","tab","cat"]
Output: [[0,1],[1,0]] 
Explanation: The palindromes are ["battab","tabbat"]

Companies: Airbnb | 26 Facebook | 5 Google | 3 Uber | 2
Similar:
Longest Palindromic Substring Medium
Shortest Palindrome Hard

Topic: 
Hash table, String, Trie

idea: 
a high frequency problem and tested by many companies
brute force is easy to come up, just find all pairs with a two level loop
,concatenate the word pairs at i and j, if we get a palindrome, then put the pair (i,j) into List<Pair> res
of course the time complexity will be O(n^2 * wordLen)
why it is hard? have to come up with O(n) algorithm???

with hash table, 
for each word, for example for a word "bat", in order to make a palindrome pair, is "tab" in the given word list? that is "battab".  tabbat 
the ij and ji will be palindrome pairs

but for word lls, not only looking for sll, but s. so word is almost a palindrome, we look for a few more chars in another word to complete it to be a palindrome 
don't feel like hashtable along will solve this. 

how about using Trie? prefix tree
no idea

fisherlei's cutting angle,   split the word into left|right, if right is palindrome, then look left reverse
  if left is palindrome, then look for right reverse
 
