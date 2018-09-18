119. Edit Distance
Description
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example
Given word1 = "mart" and word2 = "karma", return 3.
grandyang dp solution is pretty short, now fully understood 
using a distance[i][j] array to track the number of steps from word1 first i to word2 first j
then buttom up to get distance[n1] [n2]  where n1 is the length of word1 and n2 is the length of word2

compare fibonacci sequence, longest common sequence, you will find the similarity
