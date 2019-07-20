//grandyang and shaun bit check idea, runtime 24ms, faster than 83%, mem less than 94%
//cutting: look at ith bit of each numbr, count set bit and 0bit, then determine majority element's ith bit is set or 0 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            //ith bit, go through all n numbers in nums, look at each number's ith bit
            //how many 0bits == zeros, how many 1bits == ones
            //majority element's count is more than half of n, if ones > n/2, then ith bit of the majority element is set bit
            int ones = 0, zeros = 0;
            for (int num : nums) {
                if (ones > n / 2 || zeros > n / 2) break;
                
                /* //grandyang way
                if ((num & (1 << i)) != 0) ++ones;
                else ++zeros; */
                //shaun way faster than 50%
                if (((num >> i) & 1) == 1) ++ones;
                else ++zeros;
            }
            if (ones > zeros) res |= (1 << i);
        }
        return res;
    }
};
