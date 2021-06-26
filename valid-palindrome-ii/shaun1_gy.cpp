//grandyang idea, similar to shaun's, but code is much cleaner
//shaun write from understanding of the idea and code
//runtime 108ms, faster than 83%, mem less than 98%
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (s[left] != s[right]) {
                //del left                     or del right
                return isValid(s,left+1,right) || isValid(s,left,right-1);
            }
            //now s[left] == s[right]
            left++;
            right--;
        }
        return true;
    }
private:
    bool isValid(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            //now s[left] == s[right]
            left++;
            right--;
        }
        return true;
    }
};
