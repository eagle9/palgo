//shaun with grandyang idea is_valid sub function idea, accepted after 1 bug fix
//runtime 100ms, faster than 90%, mem less than 33%
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while (left < right) {
            //if (s[left++] == s[right--]) continue; //bug 1, is_valid left and right changed
            if (s[left] != s[right]) {
            
                //delete/skip 1 char from left or right
                return is_valid(s, left+1,right) || is_valid(s, left,right-1);
            }
            else {
                left++;
                right--;
            }
        }
        return true;
    }
private:
    bool is_valid(string s, int left, int right) {
        while(left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};
