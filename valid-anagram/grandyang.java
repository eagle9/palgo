public class Solution {
    //grandyang idea, shaun translate to java, beats 96%
    public boolean isAnagram1(String s, String t) {
        int n = s.length();
        if (n != t.length()) return false;
        //all lower case letters
        int [] m = new int[26];
        for (int i = 0; i < n; ++i) ++m[s.charAt(i) - 'a'];
        for (int i = 0; i < n; ++i) {
            //char ti does not match s
            //what if m[ti] >0 after scan all, this is okay
            //this must leads to some tj such m[tj] < 0
            //this is pretty savvy, since s and t have the same length
            if (--m[t.charAt(i) - 'a'] < 0) return false;
        }
        return true;
    }
    //grandyang idea, shaun code with the idea, more natural
    //beats 96%
    public boolean isAnagram(String s, String t) {
        int n = s.length();
        if (n != t.length()) return false;
        //all lower case letters
        int [] m = new int[26];
        for (int i = 0; i < n; ++i) ++m[s.charAt(i) - 'a'];
        for (int i = 0; i < n; ++i) {
            --m[t.charAt(i) - 'a'];
        }
        for (int i = 0; i < 26; i++) {
            if (m[i] != 0) return false;
        }
        return true;
    }
};
