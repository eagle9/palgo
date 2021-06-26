//jiadai c++, Your submission beats 100.00% Submissions!

class Solution {
public:
    /*
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
    	vector<vector<int>> result;
    	int n = nums.size();
    	for (int i = 0; i < (1 << n); ++i) {
    	    vector<int> path;
    	    for (int j = 0; j < n; ++j) {
    	        if ((1 << j) & i) {
    	            path.push_back(nums[j]);
    	        }
    	    }
    	    result.push_back(path);
    	}
    	return result;
    }
};
