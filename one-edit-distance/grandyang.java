//grandyang --- http://www.cnblogs.com/grandyang/p/5184698.html
//shaun modified for better read and write in java too
//Your submission beats 100.00% Submissions!, beats 98.60%

public class Solution {
    public boolean isOneEditDistance(String s, String t) {
        int n = s.length(), m = t.length();
        //length diff can not be >1
        if (Math.abs(n-m) > 1) return false;
        // abs(n-m) <= 1 now
        int lesserLen = n < m? n: m;
        for (int i = 0; i < lesserLen; i++) {
            if (s.charAt(i) != t.charAt(i)) {
                //equal length, after i must all match, don't use == to compare two String variables in java
                if (n == m) return s.substring(i + 1).equals( t.substring(i + 1));
                //s 1 fewer char,   then s[i..] == t[i+1..]
                else if (n < m) return s.substring(i).equals( t.substring(i + 1));
                //t 1 fewer char,
                else return  t.substring(i).equals( s.substring(i + 1) );
            }
            //si == ti, continue
        }
        //now for loop exit and match all, m and n must diff by 1, otherwise false
        return Math.abs(n-m) == 1;
    }
};
