161. One Edit Distance
Medium

Given two strings s and t, determine if they are both one edit distance apart.

Note: 
There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t

Example 1:
Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.

Example 2:
Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.

Example 3:
Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Facebook | 7 Uber | 3 Google | 2

Similar: Edit Distance Hard
Topic: String

I like grandyang's solution. it is modified for easier read.
It is better than jz's solution.
idea: len1 and len2
if len1 == len2
	//differ only one char
	for (int i = 0; i < len1; ++i) {
		s[i] != t[i]
	}
	if count_diff == 1 return true;
	else return false;

if abs(len1-len2) != 1 return false;
//now abs(len1 - len2) == 1
int i = 0, j = 0;
diff_found = false;
/assume len2 = len1 + 1
while (i < len1 && j < len2){
	if s[i] == t[j] {
		i++;
		j++;
	}else {
		if (!diff_found) {
			diff_found = true;
			j++;
		}else {
			//found diff again
			return false;
		}
		
	}
}
return true;

