266. Palindrome Permutation
Easy
Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true

topic: hashtable
Company: google
0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Facebook | 4 Google | 3 Amazon | 2 Microsoft | 2

Longest Palindromic Substring Medium
Valid Anagram Easy
Palindrome Permutation II Medium
Longest Palindrome Easy

Topic:
unorder_map<char,int> m;
for (char c: str) m[c]++; 
int count_odd = 0;
for (auto p: m) {
	if (p.second % 2 == 1) count_odd++;
}
if (str.size() % 2 == 0){
	if count_odd return false;
	else return true
} 
//odd len 
if (count_odd == 1) return true;
else return false;
	
}


Hint 1
Consider the palindromes of odd vs even length. What difference do you notice?
Hint 2
Count the frequency of each character.
Hint 3
If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?
