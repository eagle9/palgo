72. Edit Distance
Hard

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Microsoft | 6 Google | 6 LinkedIn | 6 Bloomberg | 4 Yahoo | 3 Facebook | 2 Square | 2 Adobe | 2

Similar:
One Edit Distance Medium
Delete Operation for Two Strings Medium
Minimum ASCII Delete Sum for Two Strings Medium

Topic: String, Dynamic Programming

grandyang dp solution is pretty short, now fully understood 
using a distance[i][j] array to track the number of steps from word1 first i to word2 first j
then buttom up to get distance[n1] [n2]  where n1 is the length of word1 and n2 is the length of word2

compare fibonacci sequence, longest common sequence, you will find the similarity
