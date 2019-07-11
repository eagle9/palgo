//grandyang 2pointer, extend palindrome substring
//not easy to come up, especially details
// quick read 
//runtime 4ms, faster than 99%, mem less than 88%
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        
        int n = s.size(), maxLen = 0, start = 0;
        //for each center index
        for (int i = 0; i < n;) {
            
            if (n - i <= maxLen / 2) break;
            
            int left = i, right = i; //start with len == 1
            //extend to right if ==
            while (right < n - 1 && s[right + 1] == s[right]) ++right;
            i = right + 1;
            //extend to both left and right if ==
            while (right < n - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right; --left;
            }
            //update maxlen
            if (maxLen < right - left + 1) {
                maxLen = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, maxLen);
    }
};
