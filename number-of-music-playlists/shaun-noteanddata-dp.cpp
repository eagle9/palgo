//shaun's own code from noteanddata's dp idea, my own way of init
//runtime 4ms, faster than 88%, mem less than 67%
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        //dp[i][j] --- number of ways to fill slots 1 to i with j unique songs, with K repeats rule
        //vector<vector<long>> dp(L+1, vector<long>(N+1));
        long dp[L+1][N+1]; //use array faster and less memory overhead, from 67% to 100%
        const long kMod = 1e9+7;
        for (int i = 0; i <= L; ++i) {
            for (int j = 0; j <= N; ++j) {
                
                if (i == 0 && j == 0) dp[i][j] = 1; //fill 0 slots with 0 songs, do nothing, =1
                else if (i ==0 && j > 0) dp[i][j] = 0; //fill 0 slots with j>0 songs, impossible = 0
                else if (i > 0 && j == 0) dp[i][j] = 0; //i>0 slots and no song, impossible = 0
                else 
                //slots 1 to i-1 filled with j-1 unique songs, 1 more not used song to fill slot i
                //slots 1 to i-1 filled with j unique songs, repeat 1 song to fill slot i
                //  follow the last K can not repeat rule, number of choices is j-K
                    dp[i][j] = dp[i-1][j-1]*(N - j+1) + dp[i-1][j]*max(j-K,0);
                //dp[i][j] %= 1000000007;
                dp[i][j] %= kMod;
                
            }
        }
            
        return (int)dp[L][N];
        
    }
};
