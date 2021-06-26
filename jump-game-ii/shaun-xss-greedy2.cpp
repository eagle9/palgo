//shaun use jump game ii's greedy idea
//runtime 4ms, faster than 99.9%, mem less than 100%
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int curMax = 0, njumps = 0, i = 0;
        while(curMax<n-1) {
            int lastMax = curMax;
            for(; i<=lastMax; i++)
                curMax = max(curMax,i+nums[i]);
            njumps++;
            //no gain jumping forward
            //if(lastMax == curMax) return -1;
            if (lastMax == curMax) return false;
        }
        //return njumps;
        return curMax >= n-1;
    }
};

