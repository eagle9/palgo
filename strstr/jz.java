//jz, Your submission beats 90.20% Submissions! use charAt is faster
class Solution {
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    public int strStr(String source, String target) {
        if (source == null || target == null) {
            return -1;
        }
        
        int n = source.length(), m = target.length();
        for (int i = 0; i <= n - m; i++) { //n-m n-1, m chars
            int j = 0;
            //java if (condition), condition must be inside ()
            //if (source.substring(i,i+m).equals(target))
            //if (target.equals(source.substring(i,i+m)))
            //    return i;
            
            for (j = 0; j <= m-1; j++) {
                if (source.charAt(i + j) != target.charAt(j)) {
                    break;
                }
            }
            // finished loop, target found
            if (j == m) {
                return i;
            }
            
        }
        return -1;
    }
}
