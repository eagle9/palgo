#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum2(vector<int> &nums, int target) {
        // Write your code here
        int count = 0;
        if (nums.empty()) return count; 
		sort(nums.begin(), nums.end());
		int n = nums.size(), left = 0, right = n-1;
		while (left < right) {
			int sum = nums[left] + nums[right];
			if (sum > target) {
				//left right
				for (int i = left; i <= right-1; ++i) {
					cout << nums[i] << "," << nums[right] << endl;
				}
				count+= right- left;
				right--;
			}else { // sum <= target
				left++;
			}
		}
		return count;

	}
};
int main() {
	vector<int> numbers = {2, 7, 11, 15};
   	int target = 24;
    //Return 1. (11 + 15 is the only pair)
	Solution s;
	int count = s.twoSum2(numbers, target);
	cout << "count=" << count << endl;
};
