//shaun's second round try from idea, runtime 8ms, faster than 80%
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxp(n); // max product of sub ending nums[i]
        vector<int> minp(n); //min product of sub ending nums[i]
        
        
        //init
        maxp[0] = nums[0];
        minp[0] = nums[0];
        int res = maxp[0]; // max product ever seen, init with min value
        
        for (int i = 1; i < n; ++i) {
            maxp[i] = max(nums[i], max(maxp[i-1]*nums[i], minp[i-1]*nums[i]));
            minp[i] = min(nums[i], min(maxp[i-1]*nums[i], minp[i-1]*nums[i]));
            res = max(res, maxp[i]);
        }
        
        return res;
        
    }
};

//reduce space since dp[i] only depends on dp[i-1]
//runtime 4ms, faster than 100%
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        //init
        int A = nums[0];   //max
        int B = nums[0];
        int res = A; // max product ever seen, init with min value
        
        for (int i = 1; i < n; ++i) {
            int A2 = max(nums[i], max(A*nums[i], B*nums[i]));
            int B2 = min(nums[i], min(A*nums[i], B*nums[i]));
            res = max(res,A2);
            A = A2;
            B = B2;
        }
        
        return res;
        
    }
};
