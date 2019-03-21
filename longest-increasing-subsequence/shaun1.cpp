//shaun idea similar to russian doll
//runtime 48ms, faster than 33%
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n,1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};

//hua dp, 52ms, faster than 27%
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        auto f = vector<int>(n, 1);
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j])
                    f[i] = max(f[i], f[j] + 1);
        return *max_element(f.begin(), f.end());
    }
};

//hua recursion, 33%
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;        
        f_ = vector<int>(n, 0);        
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, LIS(nums, i));
        return ans;
    }
private:
    vector<int> f_;
    // length of LIS ends with nums[r]
    int LIS(const vector<int>& nums, int r) {
        if (r == 0) return 1;
        if (f_[r] > 0) return f_[r];
        int ans = 1;
        for(int i = 0; i < r; ++i)
            if (nums[r] > nums[i])
                ans = max(ans, LIS(nums, i) + 1);
        f_[r] = ans;
        return f_[r];
    }
};

