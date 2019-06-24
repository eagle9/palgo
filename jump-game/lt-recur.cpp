//TLE, lt recursion, memo does not help
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        return canJumpFrom(0, nums);
    }
    bool canJumpFrom(int pos, vector<int>& nums) {
        //if (memo.find(pos) != memo.end()) return memo[pos];
        int n = nums.size();
        if (pos == n-1) return true;
        int furthest = min(pos + nums[pos], n-1);
        for (int next = pos +1; next <=furthest; ++next) {
            //if (canJumpFrom(next, nums)) return memo[pos] = true;
            if (canJumpFrom(next, nums)) return true;
        }
        //return memo[pos] = false;
        return false;
    }
private:
    unordered_map<int,bool> memo;
};

