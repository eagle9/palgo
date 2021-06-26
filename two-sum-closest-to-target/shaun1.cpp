#include <vector>
#include <iostream>
using namespace std;
//first sub wrong answer, no brain use of abs() 
//right answer when checked with jiadai code
class Solution {
public:
    /**
     * @param nums an integer array
     * @param target an integer
     * @return the difference between the sum and the target
     */
    int twoSumClosest(vector<int>& nums, int target) {
        // Write your code here
        if (nums.empty()) return target;
        sort(nums.begin(), nums.end());
		int n = nums.size(), left = 0, right = n-1;
		int mindiff = INT_MAX;
		while (left < right) {
			int sum = nums[left] + nums[right];
			/*
		   	int diff = sum	- target;
			if (abs(diff) < mindiff) {
				mindiff = diff;
			}*/
			if (sum < target) {
				if (target - sum < mindiff) mindiff = target - sum;
				left++;
			} else { //sum >= target
				if (sum - target < mindiff) mindiff = sum - target;
				right--;
			}
		}
		return mindiff;
	}
};
int main() {
	/*
	 * nums = [-1, 2, 1, -4], and target = 4.
	The minimum difference is 1. (4 - (2 + 1) = 1).
	 */
	vector<int> nums = {-1, 2, 1, -4};
	int target = 4;
	int minDiff = Solution().twoSumClosest(nums, target);
	cout << "minDiff = " << minDiff << endl;
}
