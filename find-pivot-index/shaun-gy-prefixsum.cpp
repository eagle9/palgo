//grandyang idea with prefixSum, 
//cutting  prefixSum 0 ... i-1 <i> i+1 ... n-1
//                      sum      nums[i]  sum    ==== sumAll
//runtime 28ms, faster than 90%, mem less than 92%
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumAll = 0;
        for (int x: nums) sumAll += x;
        
        int sum = 0; //prefix sum from 0 to i-1
        //0 .. i-1 <i> i+1....n-1
        for (int i = 0; i < nums.size(); i++) {
            //sum is the prefix sum from 0 to i-1
            if (sumAll - nums[i] == 2 * sum) return i;
            sum += nums[i];
        }
        return -1;
    }
};

