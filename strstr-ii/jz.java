//jz, Your submission beats 71.00% Submissions!
//time = O(n+m)
public class Solution {
    /**
     * @param source a source string
     * @param target a target string
     * @return an integer as index
     */
    public int strStr2(String source, String target) {
        if(target == null) {
            return -1;
        }
        int m = target.length();
        if(m == 0 && source != null) {
            return 0;
        }
        
        if(source == null) {
            return -1;
        }
        int n = source.length();
        if(n == 0) {
            return -1;
        }

        // mod could be any big integer
        // just make sure mod * 33 wont exceed max value of int.
        int mod = Integer.MAX_VALUE / 33;
        int hash_target = 0;

        // 33 could be something else like 26 or whatever you want
        for (int i = 0; i < m; ++i) {
            hash_target = (hash_target * 33 + target.charAt(i) - 'a') % mod;
            if (hash_target < 0) {
                hash_target += mod;
            }
        }

        int m33 = 1;
        for (int i = 0; i < m - 1; ++i) {
            m33 = m33 * 33 % mod;
        }

        int hash_source = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= m) {
                hash_source = (hash_source - m33 * (source.charAt(i - m) - 'a')) % mod;
            }

            hash_source = (hash_source * 33 + source.charAt(i) - 'a') % mod;
            if (value < 0) {
                value += mod;
            }

            if (i >= m - 1 && hash_source == hash_target) {
                // you have to double check by directly compare the string
                if (target.equals(source.substring(i - m + 1, i + 1))) {
                    return i - m + 1;
                }
            }
        }
        return -1;
    }
}
