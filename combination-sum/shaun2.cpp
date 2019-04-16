//shaun's 2nd round try, wrong answer, using subsets 
//shaun went to finish combination problem, then came back and better thinking, you have read problem and think about it 
//updated code and accepted first sub after the new thinking by myself
//runtime 16ms, faster than 82%, mem less than 36%
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(candidates, 0, 0, cur, target, res);
        return res;
    }
    
private:
    //i -- ith number
    void dfs(vector<int>& nums, int i, int curSum, vector<int>& cur, int target, vector<vector<int>>& res) {
        /*
        if (curSum == target) {
            res.push_back(cur);
            return;
        }
        if (i == nums.size()) return; */
        if (i == nums.size()) {
            if (curSum == target) res.push_back(cur);
            return;
        }
        //take ith number 0 to infinite times, according to problem statement
        for (int j = 0; curSum + nums[i]*j <= target; ++j) {
            for (int k = 0; k < j; ++k) cur.push_back(nums[i]);
            dfs(nums, i+1, curSum+j*nums[i], cur, target, res);
            for (int k = 0; k < j; ++k) cur.pop_back();
        }
    }
};

