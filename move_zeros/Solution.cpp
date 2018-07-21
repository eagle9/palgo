class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
     //Your submission beats 97.80% Submissions!
     //jiadai c++
    void moveZeroes(vector<int>& nums) {
        // Write your code here
        int i = 0; //position of non zeros stored
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j]) {
                swap(nums[i++], nums[j]);
            }
        }
    }
};
