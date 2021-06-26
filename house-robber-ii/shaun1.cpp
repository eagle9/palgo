//shaun's original idea, fixed some typos and accepted
//runtime 4ms, faster than 100%
//extension from idea to house robber
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n); // max sum from 0 to i, with nums[0] used
        vector<int> g(n); // max sum from 0 to i, nums[0] not used
        
        if (n == 0) return 0; //no house
        if (n == 1) return nums[0]; //single house
        if (n == 2) return max(nums[0], nums[1]);
        //now n >= 2, i = 0,1
        f[0] = nums[0];
        g[0] = 0;
        f[1] = f[0];
        g[1] = nums[1];
        
        for (int i = 2; i < n-1; ++i) {
            f[i] = max(nums[i] + f[i-2], f[i-1]);
        }
        //with f, nums[0] used, no use of nums[n-1]
        f[n-1] = f[n-2]; ///typo ===
        for (int i = 2; i < n; ++i) {
            //with g, nums[0] not used, you can use nums[n-1]
            g[i] = max(nums[i] + g[i-2], g[i-1]); ///typo f[i-2], f[i-1]
        }
        return max(f[n-1], g[n-1]);
        
    }
};


/*
two cases
nums[0] used
nums[0] not used
then we can determine nums[n-1] used or not
*/
