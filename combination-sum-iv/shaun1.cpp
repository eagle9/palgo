//shaun's 2d dp idea and code, runtime error, heap-buffer-overflow
#include <iostream>
#include <vector>
using namespace std;
class Solution0000 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1));
        //use nums[0] to make 0 1 .. target
        for (int j = 0; j <= target; ++j) { 
            if (j % nums[0] == 0)  
                dp[0][j] = 1;
            else 
                dp[0][j] = 0;
        }
        for (int i = 0; i < n; ++i) {
            //use nums all positive to make target = 0
            dp[i][0] = 0;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= target; ++j) {
                dp[i][j] =   dp[i-1][j];  //not use nums[i]
                for (int k  = 1; nums[i]*k <= target;  ++k) {
                    dp[i][j] +=   dp[i-k][target - nums[i]*k];
                }
            }
        }
        return dp[n-1][target];
    }
};


//shaun code with a peek at grandyang's idea
//1d dp is okay, accepted at lintcode, not leetcode(runtime error signed integer overflow)
//this is okay, g++ and a.out run okay
class Solution1 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
    
        int n = nums.size();
        vector<int> dp(target+1);
        //use nums to make target, no way
        dp[0] = 1; // dp0 = 1 is key, empty combi is 1
        
        for (int i = 1; i <= target; ++i) {
            //try all nums
            for (int j = 0; j < nums.size(); ++j) {
                if (i - nums[j] >=0){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
        
    }
};
int main() {
	vector<int> nums{3,33,333};
	Solution1 s;
	cout << s.combinationSum4(nums, 10000) << " expected 0" << endl;
	vector<int> b{1,2,3};
	cout << s.combinationSum4(b,4) << " expected 7" << endl;
}

//grandyang, runtime error, signed integer overflow
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto a : nums) {
                if (i >= a) dp[i] += dp[i - a];
            }
        }
        return dp.back();
    }
};

