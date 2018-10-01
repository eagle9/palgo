//jz beats 100.00%
public class Solution {
    public String convertPalindrome(String s) {
        int j = 0;
        for (int i = s.length() - 1; i >= 0; i--) {//find the first position that violates palindrome
           if (s.charAt(i) == s.charAt(j)) { 
               j += 1; 
           }
        }
        
        if (j == s.length()) {  //s itself is a palindrome
            return s; 
        }
        
        String suffix = s.substring(j); // the suffix that can not make palindrome
        //create prefix that combine with suffix to make palindrome
        String prefix = new StringBuilder(suffix).reverse().toString(); // 
        //recursive call to find [0,j] need to add how many chars to make palindrome
        String mid = convertPalindrome(s.substring(0, j)); 
        String ans = prefix + mid  + suffix;
        return  ans;
    }
}
