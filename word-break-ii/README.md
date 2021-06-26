140. Word Break II
Hard 1115 261 Favorite Share
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:
The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example 1:
Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]

Example 2:
Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:
Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
Companies: Google | 5 Amazon | 4 Apple | 4 Bloomberg | 4 Microsoft | 3 Snapchat | 2 Uber | 2 Pinterest | 2
Similar: 
Word Break Medium
Concatenated Words Hard
Topic: Dynamic programming, backtracking

dp[i] all breaks for string S from 0 to i
dp[1]  s.substring(0,1) in dict?  [s.substring(0,1)]

dp[i] from 0 to i, from 0 ... j ... i 
   if word = substring(j,i) in dict,  combine strings in dp[i]  and word 

linghuchong, grandyang, huahua, all use dfs with memo
start with small problems
look at s,   len,   s  = word (from 0 to i, i from 1 to len-2) + suffix, if word in dict,   then recur suffix get res, word + " " + e in res 
catsanddog
cats anddog
cats and  dog

cat sanddog
cat sand dog


