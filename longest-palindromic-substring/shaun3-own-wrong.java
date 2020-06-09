/*

naive idea, 
for each possible start i, end j, check if sij is palindromic
len N, time O(N^3) worst case

smaller problem? 
dp[i][j] stores the longest palin substring
dp[i][j+1]  
   

for each i, grow palin to left and right
the assume assume palin string are always odd len

*/

class Solution {
    public String longestPalindrome(String s) {
        int N  = s.length();
        int longest = 0, start = 0, end = 0;
        for (int i = 0; i < N; i++) {
            //from each i, expand to left and right, -j and +j
            for (int j= 1; i-j>=0 && i + j <N; j++) {
                if (s.charAt(i-j) == s.charAt(i+j)) {
                    if (1 + j + j > longest) {
                        longest = 1 + j + j;
                        start = i - j;
                        end = i+j;
                    }
                    
                }else {
                    //violates palin, no need to explore longer 
                    break; //try next i
                    
                }
            }
        }
        return s.substring(start, end+1);
    }
}
