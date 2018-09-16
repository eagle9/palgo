public class Solution {
    public boolean isPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return true;
        }

        int front = 0;
        int end = s.length() - 1;
        while (front < end) {
            while (front < s.length() && !isAlphaNumeric(s.charAt(front))){ // nead to check range of a/b
                front++;
            }

            if (front == s.length()) { // for empty string “.,,,”     
                return true; 
            }           

            while (end >= 0 && ! isAlphaNumeric(s.charAt(end))) { // same here, need to check border of a,b
                end--;
            }

            if (Character.toLowerCase(s.charAt(front)) != Character.toLowerCase(s.charAt(end))) {
                break;
            } else {
                front++;
                end--;
            }
        }
		//front >= end means all tests passed, return true. Otherwise it is break out, return false
        return end <= front; 
    }

    private boolean isAlphaNumeric (char c) {
        return Character.isLetter(c) || Character.isDigit(c);
    }
}
