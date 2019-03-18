//shaun try to apply subsets 1 idea, with adjustment
//i did come up with sort & while (i+1 < nums.size() && nums[i+1] == nums[i]) ++i;
//but put while loop at wrong place, tested not work, then no clue
//so close, big potential, 
typedef vector<int> vi; 
typedef vector<vector<int>> vvi;//so nice to use typedef
class Solution {
public:
    vvi subsetsWithDup(vi& nums) {
        vvi res;
        //subset size from 0 to nums.size()
        sort(nums.begin(), nums.end());
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
            //my first try guess add, not sure about correctness, test, not work
            //while (i+1 < nums.size() && nums[i+1] == nums[i]) ++i; 
            helper(nums,n,i+1,cur,res);
            cur.pop_back(); //not use nums[i]
            
            //put while loop here, because we tried nums[i] completely
            while (i+1 < nums.size() && nums[i+1] == nums[i]) ++i;
        }
        
    }
};

