//shaun tried to come up the dfs code, came to the thought of tracking used numbers
//para used and cur moving together is a beauty to code
//hua's permutation template, dfs and backtracking
//runtime 12ms, faster than 100%, mem less than 99%
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size());
        vector<int> cur;
        vector<vector<int>> res;
        dfs(nums, used, cur, res);
        return res;
    }
    
private:
    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& cur, vector<vector<int>>& res) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            cur.push_back(nums[i]);
            dfs(nums, used, cur, res);
            cur.pop_back();
            used[i] = false;
        }
    }
};


/*
cursor????
or smaller problem???

first pos, n choices,    then permuate n-1 numbers, remove chosen number from nums
recursion nums.size == 1, return nums[0]


cursor ----

cur.push_back(nums[i])
then we can no longer use nums[i]  |||| my thinking stop here
use a set to track a number is used or not, used and cur move together,
for combination the moving parameters are i ith index and cur
for permutation the moving parameters are used and cur


*/
