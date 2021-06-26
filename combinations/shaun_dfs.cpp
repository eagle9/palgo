//shaun 2nd round raw idea, accepted first sub
//runtime 104ms, faster than 38%, mem less than 25%
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        vector<vector<int>> res;
        dfs(n, k, 1, cur, res);
        return res;
    }
    
private:
    void dfs(int n, int k, int i, vector<int>& cur, vector<vector<int>>& res) {
        if (i > n) {
            if (cur.size() == k)
                res.push_back(cur);
            return;
        }
        
        //take i
        cur.push_back(i);
        dfs(n, k, i+1, cur, res);
        //no take i
        cur.pop_back();
        dfs(n, k, i+1, cur, res);
    }
};
