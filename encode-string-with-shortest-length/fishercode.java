class Solution {
    //fishercode, credit: https://discuss.leetcode.com/topic/71963/accepted-solution-in-java
    //344ms beats 27%
    public String encode(String s) {
        int n = s.length();
        String[][] dp = new String[n][n];

        for (int l = 0; l < n; l++) {  //l is step
            for (int i = 0; i < n - l; i++) { //start index
                int j = i + l;  //j end index
                String substr = s.substring(i, j + 1);
                // Checking if string length < 5. In that case, we know that encoding will not help.
                if (j - i < 4) {
                    dp[i][j] = substr;
                } else {
                    dp[i][j] = substr;
                    // Loop for trying all results that we get after dividing the strings into 2 and combine the   results of 2 substrings
                    for (int k = i; k < j; k++) {
                        if ((dp[i][k] + dp[k + 1][j]).length() < dp[i][j].length()) {
                            dp[i][j] = dp[i][k] + dp[k + 1][j];
                        }
                    }

                    // Loop for checking if string can itself found some pattern in it which could be repeated.
                    for (int k = 0; k < substr.length(); k++) {
                        String repeatStr = substr.substring(0, k + 1);
                        if (repeatStr != null
                                && substr.length() % repeatStr.length() == 0
                                && substr.replaceAll(repeatStr, "").length() == 0) {
                            //encode substr to ss
                            String ss = substr.length() / repeatStr.length() + "[" + dp[i][i + k] + "]";
                            if (ss.length() < dp[i][j].length()) {
                                dp[i][j] = ss;
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
}
