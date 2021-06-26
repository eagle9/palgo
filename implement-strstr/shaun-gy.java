/*

Runtime: 3 ms, faster than 33.17% of Java online submissions for Implement strStr().
Memory Usage: 39.7 MB, less than 6.10% of Java online submissions for Implement strStr().
gy, i <= m-n, tricky
*/
class Solution1 {
    public int strStr(String haystack, String needle) {
        if (needle.length() == 0) return 0;
        int m = haystack.length(), n = needle.length();
        if (m < n) return -1;
        //aaaaa
        //.  aa  i = 3,   5-2 = 3
        for (int i = 0; i <= m-n; i++) {
        
            int j = 0;
            //j = 0 to n-1
            for (; j < n; j++) {
                //if (i+j < m && haystack.charAt(i + j) != needle.charAt(j)) break;
                if (haystack.charAt(i + j) != needle.charAt(j)) break;
            }
            
            if (j == n) return i;
        }
        return -1;
    }
}

class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.length() == 0) return 0;
        int m = haystack.length(), n = needle.length();
        if (m < n) return -1;
        //aaaaa
        //.  aa  i = 3,   5-2 = 3
        for (int i = 0; i < m; i++) {
            if (i + n-1 == m) break;
            int j = 0;
            //j = 0 to n-1
            for (; j < n; j++) {
                if ( haystack.charAt(i + j) != needle.charAt(j)) break;
                
            }
            
            if (j == n) return i;
        }
        return -1;
    }
}
