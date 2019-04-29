#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * @param nums an array of integer
     * @param target an integer
     * @return an integer
     */
    int twoSum6(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());	
		int n = nums.size();
		int left = 0, right = n-1;
		int res = 0;
		while (left < right) {
			//while (left < right && left -1 >=0 && nums[left] == nums[left-1]) left++;
			//while (left < right && right+1 < n && nums[right] == nums[right+1]) right--;
			int sum = nums[left] + nums[right];
			if (sum == target) {
				res++;
				cout << nums[left] << "," << nums[right] << endl;
				left++; right--;
				while (left < right && nums[left] == nums[left-1]) left++;
				while (left < right && nums[right]== nums[right+1]) right--;
			}else if (sum < target) {
				left++;
			}else {
				right--;
			}
		}
		return res;
	}
};
void vprint(vector<int>& a) {
	for (int x: a) cout << x << " ";
	cout << endl;
}
int main() {
	vector<int> a = {1,1,2,45,46,46};
	int target = 47;
	Solution s;
	int res = s.twoSum6(a, target); 
	vprint(a);
	cout << "res=" << res << endl;

	a = {1,1,5,5};
	target = 10;
	res = s.twoSum6(a, target); 
	vprint(a);
	cout << "res=" << res << endl;
}
