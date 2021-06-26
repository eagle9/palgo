/*shaun pure own idea with sliding window, accepted after fix 1 typo and 1 corner case
//set contains not containsKey
//longest init 0, rather than Integer.MIN_VALUE
May 14 2020
Runtime: 6 ms, faster than 72.82% of Java online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 40 MB, less than 10.15% of Java online submissions for Longest Substring Without Repeating Characters.
*/
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> window = new HashSet<>();
        int left = 0, right = 0;
        int longest = 0;
        while (right < s.length()) {
            char c = s.charAt(right);
            //expand the window if new char
            if (!window.contains(c)) {
                window.add(c);
                //left -- right
                longest = Math.max(longest, right-left+1);
                right++;
            }else { // c repeats, contract left
                //from left find char == c
                while (s.charAt(left) != c) {
                    window.remove(s.charAt(left++));
                }
                //now s.charAt(left) == c
                window.remove(s.charAt(left++));
                
            }
        }
        return longest;
    }
}
