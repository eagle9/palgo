//https://www.cnblogs.com/grandyang/p/4344107.html
//grandyang c++ Your submission beats 99.80% Submissions!
//shaun adapted c++ to java, Your submission beats 84.80% Submissions! using Math.min
//Your submission beats 100.00% Submissions! java code but write my own code to track the min of 3 intergers
//dynamic programming bottom up approach
public class Solution {
    public int minDistance(String word1, String word2) {
        int n1 = word1.length(), n2 = word2.length();
        int [] [] distance = new int [n1+1][n2+1];
        //word1 first i to word2 first 0, which is empty string, delete all i chars
        for (int i = 0; i <= n1; i++) distance[i][0] = i;
        //word1 first 0 to word2 first i, add all i chars
        for (int i = 0; i <= n2; i++) distance[0][i] = i;

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    distance[i][j] = distance[i - 1][j - 1];
                } else { // word1[i-1] != word2[j-1]
                    //case1: dp[i-1][j-1] for word1 first i-1 to word2 first i-1, replace word1[i] with word2[j]
                    //case2: dp[i-1][j] for word1 first i-1 ->word2 first j, delete word1 char at i
                    //case3: dp[i][j-1] for word1 first i -> word2 first j-1,  insert a char, get word2 fi
                    //distance[i][j] = Math.min( distance[i - 1][j - 1], Math.min( distance[i - 1][j], distance[i][j - 1]) ) + 1;
                    int min = distance[i - 1][j - 1];
                    if (distance[i - 1][j] < min) 
                        min = distance[i - 1][j];
                    if (distance[i][j - 1] < min)
                        min = distance[i][j - 1];
                    distance[i][j] = min + 1;
                }
            }
        }
        return distance[n1][n2];
    }
    
};
