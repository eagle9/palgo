//jz linhuchong o(n) idea, shaun coded from memory
//runtime 8ms, faster than 99%, mem less than 100%
//cutting prefixsum trick, which computing prefixSum, track the minimum prefix sum seen so far, their difference is the subarray with max sum

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0; //store sum from 0
        int res = INT_MIN; //res to store maximum subarray sum
        int minSum = 0; //min sum from 0, init is 0, you understand??
        
        for (int x: nums) {
            sum += x;
            //minSum = min(minSum, sum); //bug 1, minSum should 1 step slower
            res = max(res, sum - minSum);
            minSum = min(minSum, sum);
        }
        return res;
    }
};
