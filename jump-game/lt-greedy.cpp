//lt greedy, 
//runtime 8ms, faster than 98%, mem less than 67%
//cutting angle, from lastPos, see if track back to 0
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int lastPos = n - 1;
        for (int i = lastPos; i >= 0; i--) {
            if (i + nums[i] >= lastPos) { // can reach lastPos from i
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
};
