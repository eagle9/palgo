//jiadai, Your submission beats 91.80% Submissions!
public class Solution {
    /**
     * @param A: a string
     * @param B: a string
     * @return: a boolean
     */
    public boolean Permutation(String A, String B) {
        int n = A.length();
        if (n != B.length()) {
            return false;
        }

        int []  count = new int[256];
        for (int i = 0; i < n; i++) {
            ++count[A.charAt(i)];
        }

        for (int i = 0; i < n; i++) {
            if (--count[B.charAt(i)] < 0) {
                return false;
            }
        }

        return true;
    }
};
