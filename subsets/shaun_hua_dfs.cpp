//shaun try hua's combination idea

//shaun 2nd try,  from nums, C(n,0), C(n,1), C(n,n)
//runtime 8ms, faster than 100%
typedef vector<int> vi; 
typedef vector<vector<int>> vvi;//so nice to use typedef
class Solution {
public:
    vvi subsets(vi& nums) {
        vvi res;
        //subset size from 0 to nums.size()
        for (int n = 0; n <= nums.size(); ++n) {
            vi cur;
            helper(nums,n,0,cur,res);
        }
        return res;
    }
private:
    //take n number combination out of nums, from start
    void helper(const vi& nums, int n, int start, vi& cur, vvi& res){
        if (cur.size() == n) {
            res.push_back(cur);
            return;
        }
        //try number from start to nums.size-1
        for (int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]); //use nums[i]
            helper(nums,n,i+1,cur,res);
            cur.pop_back(); //not use nums[i]
        }
        
    }
};


//first try, wrong answer, shaun not clear how combination idea is applied
class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(nums,0,cur,res);
        return res;
    }
    
private:
    // cur + nums[i], i+1 to end
    // cur,  i+1 to end    
    void helper(vector<int>& nums, int start,  vector<int>& cur,  vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(cur); //push_back will copy
            return;
        }
        
        for (int i = start; i < nums.size();i++) {
            cur.push_back(nums[i]);
            helper(nums, i+1, cur, res);
            cur.pop_back();
        }
        
    }
};
