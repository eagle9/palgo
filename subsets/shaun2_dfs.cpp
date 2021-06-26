//shaun round 2, first sub error, fixed two items: 
//1)  declare cur outside of dfs
//2)  dfs recursion exit use return
//idea is correct, tried with 1 test case and draw recursion tree
//accepted after quick fix, runtime 8ms, faster than 100%, mem less than 17%
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, 0, cur, res);   
        //dfs(nums, 0, vector<int>(), res)   //no working
        return res;
    }
    
private:
    //i ith number to take or not take into cur
    void dfs(vector<int>& nums, int i, vector<int>&cur, vector<vector<int>>& res) {
        if (i == nums.size()) { //all numbers are considered
            res.push_back(cur);
            return;    
        }
        
        cur.push_back(nums[i]); //take ith number
        dfs(nums, i+1, cur, res);
        cur.pop_back();
        dfs(nums, i+1, cur, res); // not take ith number
    }
};

/*
idea: 
I know there is template, but what's the idea?
for each n in nums, take or not take it

cursor type recursion or traversal type 
try 1 test case: 
       0,[], []
       /
1, [1], []         1, [], []
   /        \
2,[1,2], []  2,[1],[] 

*/
