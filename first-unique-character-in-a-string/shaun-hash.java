/*

Runtime: 11 ms, faster than 60.99% of Java online submissions for First Unique Character in a String.
Memory Usage: 47.3 MB, less than 5.71% of Java online submissions for First Unique Character in a String.

*/
class Solution {
    public int firstUniqChar(String s) {
        int [] m = new int[26]; //lower case letters
        char [] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            m[c - 'a'] += 1;
        }

        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            if (m[c - 'a'] == 1) return i;
        }
        return -1;

    }
}
