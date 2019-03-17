//shaun dp[i]: list of word breaks for substr 0 to i-1
//heap-buffer-overflow
class Solution {
public:
    //unordered_map<string, vector<string>> m;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int N = s.size();
        
        //dp[i] list of breaks for s from 0 to i-1
        vector<vector<string>> dp(N, vector<string>());
        dp[0].push_back("");
        
        
        for (int i = 1; i <= N; ++i) {
            string cur = s.substr(0,i);
            if (dict.count(cur)) dp[i].push_back(cur);
            for (int j = 1; j < i; ++j) {
                string prefix = cur.substr(0, j); //0..j-1, len j
                string suffix = cur.substr(j);  //j to end
                // s = prefix + suffix
                if (dict.count(suffix) == 0) continue;
                
                //suffix in dict
                //res1 solution to smaller string suffix
                
                /*vector<string> res1 = dp[j];
                for (string& wb : dp[j]) {
                    dp[i].push_back(wb + (wb.empty() ? "" : " ") + suffix);
                }
                */
                dp[i] = append(dp[j], suffix);
                dp[i].insert(dp[i].end(), dp[i].begin(), dp[i].end());
            }
            
        }
        return dp[N];
    }
private:
    vector<string> append(const vector<string>& prefixes, const string& word) {
        vector<string> results;
        for(const auto& prefix : prefixes)
            results.push_back(prefix + " " + word);
        return results;
    }
};
