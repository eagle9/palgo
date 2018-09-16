public class Solution {
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    public boolean isPalindrome(String s) {
        // write your code here
        int start = 0;
        int end = s.length()-1;
        if (start >= end) return true; //empty or single char String
        while (start < end) {
            if (!isAlphaNumberic(s.charAt(start))) start++;
            if (!isAlphaNumberic(s.charAt(end))) end--;
            if (start < end) {
                if ( Character.toLowerCase(s.charAt(start)) == Character.toLowerCase(s.charAt(end)) ){
                    start++;
                    end--;
                    continue;
                }else {
                    return false;
                }
            }
            
        }
        //pass all tests
        return true;
        
    }
    public boolean isAlphaNumberic(char c) {
        if (c>= '0' && c<='9') return true;
        if (c>= 'a' && c<='z') return true;
        if (c>= 'A' && c<='Z') return true;
        return false;
    }
}
