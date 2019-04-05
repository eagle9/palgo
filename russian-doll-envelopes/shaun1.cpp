//shaun first try, wrong answer
class Solution1 {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        if (n == 0) return 0;
        vector<int> dp(n,1);
        vector<int> idx(n);
        dp[0]= 1; 
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j].first < envelopes[i].first &&
                    envelopes[j].second< envelopes[i].second) {
                    if (dp[j] + 1 > dp[i] && idx[j] == j) {
                        dp[i] = dp[j] + 1;
                        idx[i] = i;
                    }
                    
                }else {
                    if (dp[j] > dp[i]) {
                        dp[i] = dp[j];
                        idx[i] = idx[j];
                    }
                }
            }
        }
        return dp[n-1];
    }
};

//shaun idea with check with grandyang, accepted, faster than 44%
class Solution2 {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
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

//shaun recur, wrong answer
class Solution3 {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        //now n >= 2
        sort(envelopes.begin(), envelopes.end());
        helper(envelopes,0);
        return res_;
    }
private: 
    int res_ = 1;
    int helper(vector<pair<int, int>>& envelopes,int start) {
        if (start == envelopes.size()) return 1;
        int dp = 1;
        if (envelopes[start].first < envelopes.back().first &&
            envelopes[start].first < envelopes.back().second) {
            dp = 1+ helper(envelopes, start+1);
            
            
        }
        /*
        else  {
            dp = helper(envelopes, start+1);
            
        }*/
        res_ = max(res_,dp);
        return dp;
    }
};


//grandyang dp code for reference, runtime 524ms, faster than 24%, mem less than 95%
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int res = 0, n = envelopes.size();
        vector<int> dp(n, 1);
        sort(envelopes.begin(), envelopes.end());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
/*

idea:  
  find the max envelop 
    now i understand a inside b and b inside c 
   sort the envolopes by comparsion, by width 
    0       1     2      3 
   [2,3]   [5,4] [6,4]  [6,7] 
   dp[i] russian envelop number from 0 to i 
   idx[i]   max r envelop last envelop index 
   dp[0] = 1, idx[0] = 0 
   dp[1]  e0 inside e1?  yes  dp[0] + 1 = 2, idx[1] = 1 
    dp[2]: e0 inside e2? yes  2, 2, 
          e1 inside e2? no  2, i = 1 
          max is dp[2] = max(2,2)=2, i = 1,2 
dp[3] 
   e0 inside e3,  2, i=3 
   e1 inside e3,  3, i=3  
    e2 inside e3, no, 2, i=2,2 
    
    */
