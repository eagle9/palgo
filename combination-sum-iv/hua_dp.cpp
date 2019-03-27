#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0); // dp[i] # of combinations sum up to i
        dp[0] = 1;
        for (int i = 1; i <= target; ++i)
            for (const int num : nums)
                if (i - num >= 0)
                    dp[i] += dp[i - num];           
        return dp[target];
    }
};
int main() {
	vector<int> nums{3,33,333};
	Solution s;
	cout << s.combinationSum4(nums, 10000) << " expected 0" << endl;
	vector<int> b{1,2,3};
	cout << s.combinationSum4(b,4) << " expected 7" << endl;
}
/*
[3,33,333]
10000
*/
