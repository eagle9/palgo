//using idea for 1, sort the numbers and not use repeated number each branching
//draw a recursion tree
//how to come up the idea?   draw a recursion tree for a simple example
//runtime 24ms, faster than 96%, mem less than 89%

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vi cur;
        vvi res;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size());
        
        dfs(nums,used,cur,res);
        return res;
    }
private:
    //take n numbers out of nums for permu
    //used[i]: ith number used
    void dfs(const vi& nums, vector<bool>& used, vi& cur, vvi& res) {
        if (cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }
        //try all numbers in nums
        for (int i = 0; i < nums.size();++i) {
            if (used[i]) continue;
            
            cur.push_back(nums[i]);
            used[i] = true;
            dfs(nums,used,cur,res);
            cur.pop_back();
            used[i] = false;
            while (i +1 < nums.size() && nums[i+1] == nums[i]) ++i;
        }
    }

};
