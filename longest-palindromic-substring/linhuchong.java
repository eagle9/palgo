//jz linhuchong beats 75%, fully understand now
//idea is enumerate growing palindrome from each center position 
//time = O(n^2)
//challenge can you do it O(n)? a special algorithm will be used
public class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }
        
        //use typical examples 
        // sd aba kj --> left=right=3,   len=3,  start = 3 - 1 = 2
        // 01  abba   jk   --> left=3, right = 4, start = left - 2 + 1 = 2
        int start = 0, len = 0, longest = 0;
        //the substring length could be odd or even, 
        for (int i = 0; i < s.length(); i++) {
            len = grow(s, i, i);  //for odd length
            if (len > longest) {
                longest = len;
                start = i - len / 2;
            }
            
            len = grow(s, i, i + 1); //why this case? for even length
            if (len > longest) {
                longest = len;
                start = i - len / 2 + 1;
            }
        }
        
        return s.substring(start, start + longest);
    }
    
    //grow palindrome from left and right
    private int grow(String s, int left, int right) {
        int len = 0;
        //grow palindrome from left-- and right++
        while (left >= 0 && right < s.length()) {
            if (s.charAt(left) != s.charAt(right)) {
                break;
            }
            //char matches at left and right, left might equal to right at beginning
            len += left == right ? 1 : 2;
            left--;
            right++;
        }
        
        return len;
    }
}
