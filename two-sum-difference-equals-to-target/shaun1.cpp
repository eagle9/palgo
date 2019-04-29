#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    /*
     * @param nums an array of Integer
     * @param target an integer
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum7(vector<int> &nums, int target) {
        // write your code here
        vector<int> result(2);
        unordered_map<int, int> table;
		/*
        if (target < 0) {
            target = -target;
        }*/

        for (int i = 0; i < nums.size(); ++i) {
			int other1 = nums[i] - target;
			int other2 = nums[i] + target;
            if (table.find(other1) != table.end()) {
                result[0] = table[other1];
                result[1] = i + 1;
                break;
            }
            else if (table.find(other2) != table.end()) {
                result[0] = table[other2];
                result[1] = i + 1;
                break;
            }
            else {
                table[nums[i]] = i + 1;
            }
        }
        
        return result;
     }
};
int main() {
	/*
	 * Given nums = [2, 7, 15, 24], target = 5
return [1, 2] (7 - 2 = 5)*/
	vector<int> nums = {2,7,15,24};
	int target  = 5;
	vector<int> res = Solution().twoSum7(nums,target);
	for (int x: res) cout << x << ",";
   	cout << endl;	
}
