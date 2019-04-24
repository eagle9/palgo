//jz linhuchong o(n) idea, shaun coded from memory
//runtime 8ms, faster than 99%, mem less than 100%
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0; //store sum from 0
        int res = INT_MIN; //res to store maximum subarray sum
        int minSum = 0; //min sum from 0, init is 0, you understand??
        
        for (int x: nums) {
            sum += x;
            res = max(res, sum - minSum);
            minSum = min(minSum, sum);
        }
        return res;
    }
};
