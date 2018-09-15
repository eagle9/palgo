//jiadai Your submission beats 95.80% Submissions!

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if (n == 0 || n == 1) {
            return nums;
        }
       
        //from tail, find number that drops 
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        
        if (i >= 0) {
            int j = n - 1;
            //j from tail before i, find nums[j] that > nums[i]
            while (j > i && nums[j] <= nums[i]) {
                --j;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
        
        return nums;
    }
};
