class Solution {
    //shaun idea, beats 97%
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
