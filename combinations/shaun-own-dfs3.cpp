//shaun from memory after long time
//dfs with back tracking
//runtime 84ms, faster than 66%, mem less than 80%
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        vector<vector<int>> res;
        helper(n,k, 1, cur, res);
        return res;
    }
private:
    void helper(int n, int k, int start, vector<int>& cur, vector<vector<int>>& res) {
        if (cur.size() == k) {
            res.push_back(cur); //a copy of cur is pushed into res
            return;
        }
        for (int i = start; i <= n; ++i) {
            cur.push_back(i);
            helper(n, k, i+1, cur, res);
            cur.pop_back();
        }
        
    }
};

