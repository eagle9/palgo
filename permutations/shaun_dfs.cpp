//shaun use hua's permu template, 
//runtime 12ms, faster than 100%
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vi cur;
        vvi res;
        vb used(nums.size());
        dfs(nums,nums.size(),used,cur,res);
        return res;
    }
private:
    //take n numbers out of nums for permu
    //used[i]: ith number used
    void dfs(const vi& nums, int n, vb& used, vi& cur, vvi& res) {
        if (cur.size() == n){
            res.push_back(cur);
            return;
        }
        //try all numbers in nums
        for (int i = 0; i < nums.size();++i) {
            if (used[i]) continue;
            used[i] = true;
            cur.push_back(nums[i]);
            dfs(nums,n,used,cur,res);
            cur.pop_back();
            used[i] = false;
        }
    }
};
