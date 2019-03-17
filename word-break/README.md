139. Word Break
Medium
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:
The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
Companies: Facebook | 13 Amazon | 13 Google | 11 Uber | 6 Apple | 5 Bloomberg | 5 Yelp | 3 Microsoft | 3 Snapchat | 2 Walmart Labs | 2 Qualtrics | 2 VMware | 2 Twilio | 2
Similar: Word Break II Hard
Topic: dynamic programming

107. Word Break, lintcode
Description
Given a string s and a dictionary of words dict, determine if s can be break into a space-separated sequence of one or more dictionary words.

Example
Given s = "lintcode", dict = ["lint", "code"].

Return true because "lintcode" can be break as "lint code".

idea: 
str from 0 to i, break 0 to j, j+1 to i
   	dp[0] = true
    dp[1] = str.substr(0,1) in dict 
	for (int i = 1; i <= n-1; ++i) {
   		for (int j = 0; j < i; ++j) {
			dp[i] = false;		
   			if dp[j]  && str(j+1 to i ) in dict {
				dp[i] = true;
				break;
			}
		}
	}
	return dp[n-1]
