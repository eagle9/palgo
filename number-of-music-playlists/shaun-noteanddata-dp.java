/*
http://www.noteanddata.com/leetcode-920-Number-of-Music-Playlists-solution-note.html

设置动态规划数组dp[i][j], 表示第i个位置，在N首歌曲里面，放了j首不同的歌曲的个数， 并且符合K的条件
noteanddata idea, found easier to understand, but still a lot of details 
runtime 4ms, faster than 87%, mem less than 100%
*/
class Solution {
    //N -- number of unique songs
    //L -- L slots, fill 1 slot with 1 song
    //K -- every song play once, K others before a song can be played again
    public int numMusicPlaylists(int N, int L, int K) {
        long[][] dp = new long[L+1][N+1];
        //dp[i][j]  len i with j different songs, K others 
        for(int i = 1; i <= L; ++i) {
            for(int j = 1;j <= N; ++j) {
                if(i < j) dp[i][j] = 0; //i slots in the list, but # of unique songs =j < i, can not fill
                else if(i == 1 && j == 1) dp[i][j] = N; //fill 1 slot with 1 unique song, N choices
                else if(i > 1 && j == 1) { //fill more than 1 slot with 1 unique song
                    if(K == 0) dp[i][j] = N; //more than 1 slots, 1 unique song, N choices, repeat the single song 
                    else dp[i][j] = 0; //K > 0, at least two unique songs, so can not do it
                }
                else {
                    
                    //              a                          b
                    //i-1 slots filled with j-1 unique songs
                    //  N-j+1 songs left, to fill slot i with 1 song
                    //  if the song comes from N-j+1, then j unique songs, this is case a
                    // to fill slot i with 1 song, this song is a repeat of some song used
                    //so the number of unique songs used no change, say j
                    //the last K songs can not be used again for slot i, so we the number of choices is j- K (>0? )
                    dp[i][j] = dp[i-1][j-1] * (N-j+1) + dp[i-1][j] * Math.max(j-K, 0);
                    
                    //As the answer can be very large, return it modulo 10^9 + 7.
                    dp[i][j] %= 1_000_000_007;
                }
                
            }
        }
        return (int)dp[L][N];
    }
}
