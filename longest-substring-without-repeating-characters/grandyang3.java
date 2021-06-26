/*
grandyang use hashset
Runtime: 25 ms, faster than 80.80% of Java online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 40.2 MB, less than 10.71% of Java online submissions for Longest Substring Without Repeating Characters.

*/
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int res = 0, left = 0, right = 0;
        HashSet<Character> t = new HashSet<Character>();
        while (right < s.length()) {
            if (!t.contains(s.charAt(right))) {
                t.add(s.charAt(right++));
                res = Math.max(res, t.size());
            } else {
                t.remove(s.charAt(left++));
            }
        }
        return res;
    }
}

