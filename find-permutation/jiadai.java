//jiadai, c++, Your submission beats 71.67% Submissions!
//jiadai, java, Your submission beats 90.72% Submissions!
public class Solution {
    /**
     * @param s: a string
     * @return: return a list of integers
     */
    public int[] findPermutation(String s) {
        int len = s.length();
        int [] result = new int[1 + len];
        result[0] = 1;
        int i = 1;
        
        while (i <= len) {
            result[i] = i + 1;
            if (s.charAt(i - 1) == 'D') {
                int j = i;
                while (i <= len && s.charAt(i - 1) == 'D') {
                    ++i;
                }

                for (int k = j - 1, c = i; k < i; ++k, --c) {
                    result[k] = c;
                }
            }
            else {
                ++i;
            }
        }

        return result;
    }
};
