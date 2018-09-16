//grandyang c++, Your submission beats 86.00% Submissions!
//shaun write in java,Your submission beats 99.20% Submissions!
public class Solution {
    public boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1 ;
        while (left < right) {
            if (!isAlphaNum(s.charAt(left))) left++;
            else if (!isAlphaNum(s.charAt(right))) right--;
            else if (Character.toUpperCase(s.charAt(left))  != Character.toUpperCase(s.charAt(right)))
                return false;
            else { //char at left and right match
                left++; right--;
            }
        }
        return true;
    }
    private boolean isAlphaNum(char ch) {
        if (ch >= 'a' && ch <= 'z') return true;
        if (ch >= 'A' && ch <= 'Z') return true;
        if (ch >= '0' && ch <= '9') return true;
        return false;
    }
};
