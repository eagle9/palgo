#include <stdio.h>
#include <ctype.h>
//shaun's original idea, first sub not accepted!!! can you believe it. I tried to be quick turnaound
//didnt read the problem statement, especially with easy problem, no bug is very important.
//for such a simple problem, fixed many bugs, finally accepted. check the comments for the bugs
//finally accepted, runtime 8ms, faster than 99%, mem less than 41%
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int n = s.size();
        int left = 0, right = n-1;
        while (left < right) {
            //cout << s[left] << " " << s[right] << endl;
            if (!isalnum(s[left])) {
            //if (!is_valid(s[left])) {
                left++;
                continue;
            }
            
            //if (!is_valid(s[right])) {
            if (!isalnum(s[right])) {
                right--;
                continue;
            }
            //while (!is_valid(s[right])) right--;
            //while (!isalnum(s[left]) && left < n) left++;
            //while (!isalnum(s[right]) && right >=0) right--;
            //if (s[left++] != s[right--]) return false;
            if (tolower(s[left++]) != tolower(s[right--])) return false;
            
        }
        return true;
    }
private:
    bool is_valid(char & c) {
        if ( c >= '0' && c <= '9') return true;
        if ( c >= 'a' && c <= 'z') return true;
        if ( c >= 'A' && c <= 'Z') return true;
        return false;
    }
};
