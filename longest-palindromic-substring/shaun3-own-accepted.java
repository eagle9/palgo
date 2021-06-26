/*
Runtime: 24 ms, faster than 67.18% of Java online submissions for Longest Palindromic Substring.
Memory Usage: 38.3 MB, less than 35.08% of Java online submissions for Longest Palindromic Substring.

shaun own idea, without dp
for each start, try to stretch the palindrome
but the hard part is to recognize there are two senarios expand from a single char
or expand from two chars
*/
class Solution {
    public String longestPalindrome(String s) {
        int N  = s.length();
        if (N==0) return "";
        
        int longest = 1, start = 0;
        for (int i = 0; i < N; i++) {
            //from each i, expand to left and right, -j and +j
            int left = i, right = i;
            
            while (left >=0 && right < N && s.charAt(left) == s.charAt(right)) {
                    if (right - left +1 > longest) {
                        longest = right - left + 1;
                        start = left;
                    }
                    left--;
                    right++;
            }
            
            left = i;
            right = i+1;
            
            while (left >=0 && right < N && s.charAt(left) == s.charAt(right)) {
                    if (right - left +1 > longest) {
                        longest = right - left + 1;
                        start = left;
                    }
                    left--;
                    right++;
            }
            
        }
        return s.substring(start, start+longest);
    }
}

