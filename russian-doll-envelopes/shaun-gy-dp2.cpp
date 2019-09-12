//shaun sort and dp idea with check with grandyang
//runtime 468ms, faster than 56%, mem less than 17%
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes0) {
        vector<pair<int,int>> envelopes;
        for (auto v: envelopes0) {
            envelopes.push_back({v[0],v[1]});
        }
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        if (n == 0) return 0;
        
        //dp[i] russian doll ending at i
        vector<int> dp(n,1);
        int res = 1;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j].first < envelopes[i].first &&
                    envelopes[j].second< envelopes[i].second) {
                        dp[i] = max(dp[i],dp[j] + 1);
                        
                }
            }
            //dp[i]
            //res = max(res,dp[i]);
        }
        //return dp[n-1]; ---> wrong answer, how come!
        return *max_element(dp.begin(), dp.end());
    }
};
