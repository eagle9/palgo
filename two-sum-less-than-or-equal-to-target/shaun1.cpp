#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * @param nums an array of integer
     * @param target an integer
     * @return an integer
     */
    int twoSum5(vector<int> &nums, int target) {
        // Write your code here
        if (nums.size() == 0) {
            return 0;
        }
		int n = nums.size();
		sort(nums.begin(), nums.end());
		int count = 0, left = 0, right = n-1;
		while (left < right) {
		 	int sum = nums[left] + nums[right];
			if (sum <= target) {
				//left left+1     right-1    right
				//left pairs with left+1 ... right all <= target
				for (int i = left+1; i <= right; ++i) 
					cout << nums[left] << "," << nums[i] << endl;
				count+= right-left; 
				left++;
			}else { // sum > target
				right--;
			}	
		}
		return count;
	}
};
int main() {
/*Given nums = [2, 7, 11, 15], target = 24. 
Return 5. 
2 + 7 < 24
2 + 11 < 24
2 + 15 < 24
7 + 11 < 24
7 + 15 < 25*/
	vector<int> nums = {2,7,11,15};
	int target  = 24;
	Solution s;
	int count = s.twoSum5(nums,target); 
	cout << "count=" << count << endl;
};
