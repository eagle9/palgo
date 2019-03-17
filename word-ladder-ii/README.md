126. Word Ladder II
Hard

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]

Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Amazon | 7 Facebook | 4 Google | 4 LinkedIn | 3 Uber | 3 Microsoft | 2 Oracle | 2 Pinterest | 2

Similar:
Word Ladder Medium

Topic: Array, String, Backtracking, Breadth-first search

idea: similar to word ladder, how to store the ladder(sequence)? 
if endWord not in dict, return empty vector/list 
for word in queue
	for each letter in word
		for a to z
			word to one letter diff newWord
			if dict.count(newWord) == 0  continue
			//newWord in dict

if new word == endWord , //return step+1  
  now we want to find all the shortest ladders/sequences
  no longer return, add the ladder to res vector
	how to get the ladder? 
	all word in queue
		word one letter diff to new word
    use a map prev[newWord] = word
	word1 = newWord
	vector<string> ladder{word1}; 
	
	while prev[word1] != beginWord 
		ladder.push_front(prev[word1])
		word1 = prev[word1]
	//prev[word1] == beginWord
	ladder.push_front(beginWord)
	res.push_back(ladder)

newWord !== endWord
dict.erase(newWord)
q.push(newWord)
	
		
		
