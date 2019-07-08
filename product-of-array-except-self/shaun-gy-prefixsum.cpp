//grandyang prefixsum/product for array, 
//runtime 40ms, faster than 87%, mem less than 53%
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), right = 1;
        vector<int>res(n);
        
        res[0] = 1;
        //prefix product from left
        for (int i = 1; i < n; ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        //right is suffix product from right
        for (int i = n - 1; i >= 0; --i) {
            // res[i]: nums[0] * ... * nums[i-1]
            // right:  nums[i+1] ... * nums.back()
            res[i] *= right;
            right *= nums[i];
        }
        return res;

    }
};
