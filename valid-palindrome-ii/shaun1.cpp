//shaun original idea, first sub wrong answer!!!!!
//second sub still wrong answer
//finally realized there is choice to make when s[left] != s[right]
// del left or right, depending on the choice,  different checking method
//finally accepted, runtime 108ms, faster than 83%, mem less than 98%

class Solution {
public:
    //s only lower case letters, non-empty
    bool validPalindrome(string s) {
        return valid_left(s) || valid_right(s);
    }
    
    bool valid_left(string& s) {
        int left = 0, right = s.size()-1;
        bool del1c = false;
        while (left < right) {
            if (s[left]!= s[right]) {
                if (!del1c) {
                    del1c = true;
                    left++;
                    continue;
                }else {
                    return false;
                }
            }
            //s[left] == s[right], more check
            left++;
            right--;
        }
        //passed all checks
        return true;
    }
    bool valid_right(string& s) {
        int left = 0, right = s.size()-1;
        bool del1c = false;
        while (left < right) {
            
            if (s[left]!= s[right]) {
                if (!del1c) {
                    del1c = true;
                    right--;
                    continue;
                }else {
                    return false;
                }
            }
            //s[left] == s[right], more check
            left++;
            right--;
        }
        //passed all checks
        return true;
    }
};
