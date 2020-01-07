i/*
8 = 2 4
    [2] 4 = 2x2
            [2 2]  2=2x1
                    [2 2 2] 1
        4 = 4x1
        [2 4] 1
    [4] 2
        [4 2] 1
    
    2 2 2
    
12 = 2 6
     2 2 3
     3 4

can only divide with a factor which is >= factor used dfs

shaun's first try, wrong answer, kind of get some but no clear 
*/

class Solution1 {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> cur;
        vector<vector<int>> res;
        
        helper(n, 2, n, cur, res);
        return res;
    }
    
    //try factor i= k ...n on r, if okay, try i .. n on r/i
    void helper(int n, int k, int r, vector<int>& cur, vector<vector<int>>& res) {
        //try all factors >= k
        
        for (int i = k; i <=n; i++) {
            if (r % i == 0 && r /i >= k) {
                cur.push_back(i);
                helper(n, i, r/i, cur, res);
            }
        }
       
        //recur exit
        
    }
};

//grandyang idea, cutting, n/i if okay, cur.push_back(i)
// n = n/i now, 
//runtime 112ms, faster than 39%, mem less than 100%
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> cur;
        vector<vector<int>> res;
        
        helper(n, 2, cur, res);
        return res;
    }
    
    //try factor i= k ...n on r, if okay, try i .. n on r/i
    void helper(int n, int start, vector<int>& cur, vector<vector<int>>& res) {
        if (n == 1) {
            //if (!cur.empty()) res.push_back(cur);
            if (cur.size() > 1) res.push_back(cur); //must have two factors at least
        } else {
            for (int i = start; i <=n; i++) {
                //if (n % i == 0 && n /i >= start) {
                if (n % i == 0) {
                    cur.push_back(i);
                    helper(n/i,i, cur, res);
                    cur.pop_back();
                }
            }
        }
       
        //recur exit
        
    }
};


