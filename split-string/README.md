680. Split String
Description
Give a string, you can choose to split the string after one character or two adjacent characters, and make the string to be composed of only one character or two characters. Output all possible results.

Example
Given the string "123"
return [["1","2","3"],["12","3"],["1","23"]]

Related Problems
concatenated string with uncommon characters of two strings, word break ii, word break, subsets, subsets ii

Difficulty: easy

jz and lxp. similar idea but lxp is faster because substring is only called once for each recursion, use index to track last split position
