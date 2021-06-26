//Runtime: 0 ms, faster than 100.00% of Java online submissions for Longest Common Prefix.
//picked up my own idea
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        String prefix = strs[0];
        for (int i = 1; i < strs.length; i++) {
            prefix = findPrefix(strs[i], prefix);
            if (prefix.length() == 0) return prefix;
        }
        return prefix;
    }
    
   

    //longest prefix of a and b
    private String findPrefix(String a, String b) {
        int i = 0,len = Math.min(a.length(),b.length());
        //if (len == 0) return ""; //after comment, okay too

        while (i < len ) {
            if (a.charAt(i) == b.charAt(i)) i++;
            else break; ///bug fix 1
        }
        //i == number of equal chars
        return a.substring(0,i);
    }

}
