//cutting angle accumulate end_with each letter
/*
with out this angle, i was faced with hard dealing with empty subseq and repetitive subseq
testing with a example that leads repetition
a --- a: 1
ab ---a: 1,  b: 2 (ab, b)
aba --a: 3(aa, aba, ba, a), b: 2 

//shaun with the end_with dp idea, actually dp with many states
//accepted after fixing two bugs
//runtime 8ms, faster than 67%, mem less than 90%
*/
class Solution1 {
public:
    int distinctSubseqII(string S) {
        constexpr int MOD = 1e9+ 7;
        int N  = S.length();
        vector<int> end_with(26,0);   //number of subsequences that ending with a letter
        for (int i = 0; i < N; ++i) {
            
            int count = 1; //no use of previous end_with prev step, just char ic
            for (int j = 0; j < 26; ++j) {
                //append char ic to each group of subseq end_with each letter
                count = (count+ end_with[j]) % MOD;
            }
            //update for the current char
            end_with[S[i] - 'a'] = count % MOD;
        }
        
        //summarize
        int ans = 0;
        //bug 1   j = 0 to N, should for all 26 letters, not N
        for (int j = 0; j < 26; ++j) {
            ans = (ans + end_with[j]) % MOD;
        }
        return ans;
    }
};

//doing % MOD only once 
//runtime 4ms, faster than 96%, mem less 69%
class Solution {
public:
    int distinctSubseqII(string S) {
        constexpr int MOD = 1e9+ 7;
        int N  = S.length();
        vector<long> end_with(26,0);   //number of subsequences that ending with a letter
        for (int i = 0; i < N; ++i) {
            
            long count = 1L; //no use of previous end_with prev step, just char ic
            for (int j = 0; j < 26; ++j) {
                //append char ic to each group of subseq end_with each letter
                count += end_with[j];
            }
            //update for the current char
            end_with[S[i] - 'a'] = count % MOD;
        }
        
        //summarize
        long ans = 0;
        //bug 1   j = 0 to N, should for all 26 letters, not N
        for (int j = 0; j < 26; ++j) {
            ans += end_with[j];
        }
        //return (int) ans % MOD; //bug 1, int cast ans first
        //return (int) (ans % MOD); //okay, actually since MOD is int, so another cast int not needed
        return ans % MOD;
    }
};


