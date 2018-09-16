//based on j9 java code
//Your submission beats 94.04% Submissions!
//Your submission beats 61.59% Submissions!

class Solution {
public:
    /**
     * @param s: a string
     * @return: nothing
     */
    bool validPalindrome(string &s) {
        // Write your code here
        int left =0, right = s.length()-1;
        while (left < right) {
            if (s.at(left) != s.at(right)) 
                break;
            left++;
            right--;
            
        }
        if (left >= right) 
            return true;
        return isSubPalindrome(s,left + 1, right) 
            || isSubPalindrome(s,left,right-1);
    }
    
private:
    bool isSubPalindrome(string &s,int left, int right) {
        while (left < right) {
            if (s.at(left) != s.at(right))
                return false;
            left++;
            right--;
        }
        return true;
    }
};
