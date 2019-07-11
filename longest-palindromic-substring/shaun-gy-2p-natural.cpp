//runtime 32ms, faster than 61%, mem less than 19%
//cutting, check and expand palindrome substring to both left and right, hence 2 pointers
// try all center point
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int n = s.size(), maxLen = 0, start = 0;
        for (int i = 0; i < n - 1; ++i) {
            searchPalindrome(s, i, i, start, maxLen);
            searchPalindrome(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }
    
    //check and expand palindrome substring from [left.. right]
    void searchPalindrome(string s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left; ++right;
        }
        
        //left [. palindrome..] right
        //len = right-1 - (left+1) + 1 = right - left -1 
        if (maxLen < right - left - 1) {
            start = left + 1;
            maxLen = right - left - 1;
        }
    }
};
