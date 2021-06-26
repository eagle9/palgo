#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    /**
     * @param nums an array of integers
     * @return the number of unique integers
     */
	//return number of unique numbers
	//move unique numbers to the front, do it in place
    int deduplication(vector<int>& nums) {
    	unordered_set<int> visited;
    	int i = 0;  //index for number that is not yet seen
    	for (int j = 0; j < nums.size(); ++j) {
    		if (visited.count(nums[j]) == 0) {
    			visited.insert(nums[j]);
    			//int temp = nums[i];
    			//nums[i] = nums[j];
    			//nums[j] = temp;
				nums[i] = nums[j];
    			i++;
    		}
    	}
		return i;
    }
};

int main() {
	vector<int> nums = {1,3,1,4,4,2};
	Solution sol;
	int res = sol.deduplication(nums);
	cout << "res=" << res << endl;
	for (int x: nums) cout << x << " ";
	cout << endl;
}
