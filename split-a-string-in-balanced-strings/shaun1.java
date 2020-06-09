/*

Runtime: 0 ms, faster than 100.00% of Java online submissions for Split a String in Balanced Strings.
Memory Usage: 37.7 MB, less than 100.00% of Java online submissions for Split a String in Balanced Strings.

shaun own idea
*/

class Solution {
    public int balancedStringSplit(String s) {
        int left = 0, right = 0, count = 0;
        for (int i = 0; i < s.length(); i++) {
            
            if (s.charAt(i) == 'L') left++;
            else right++;
            
            if (left == right & left > 0) {
                count++;
                left = 0;
                right = 0;
            }
        }
        return count;
    }
}
