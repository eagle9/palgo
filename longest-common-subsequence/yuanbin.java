//yuanbin Your submission beats 98.60% Submissions!
//Math.max is slow if you just have several numbers
//without using Math.max, beats 100.00%
public class Solution {
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    public int longestCommonSubsequence(String A, String B) {
        if (A == null || A.length() == 0) return 0;
        if (B == null || B.length() == 0) return 0;

        int lenA = A.length();
        int lenB = B.length();
        int[][] lcs = new int[1 + lenA][1 + lenB]; //lcs[i][j] stores the length of lcs for  A[0..i-1] and B[0..j-1]

        for (int i = 0; i < lenA; i++) {
            for (int j = 0; j < lenB; j++) {
                if (A.charAt(i) == B.charAt(j)) {
                    lcs[i+1][j+1] = 1 + lcs[i][j]; //extend the lcs with char at i
                } else {  //A[i] != B[j]
                    //lcs[i+1][j+1] = Math.max(lcs[i][j+1], lcs[i+1][j]);
                    int max = lcs[i][j+1];
                    if (lcs[i+1][j] > max) max = lcs[i+1][j];
                    lcs[i+1][j+1] = max;
                }
            }
        }

        return lcs[lenA][lenB]; //this one stores the length of lcs for A[0..LenA-1] and B[0..LenB-1], or A and B
    }
}
