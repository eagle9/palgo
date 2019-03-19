//shaun raw idea, but details checked with grandyang code
//you have to come up with longer permutations to find the rule
// 1 3 2
// 2 1 3  not a good sample to come up the rule

// 1 2 7 4 3 2 1
// 1 3 7 4 2 2 1
// 1 3 1 2 2 4 7 done

//shaun code entirely from memory of the idea
//runtime 12ms, faster than 99.40%
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        //1 3 2
        //2 3 1
        //go from right to left, up slope, keep going, find first down slope number, candiate to ++
        int i = n-2;
        while (i >= 0 && nums[i] >= nums[i+1]) --i;
        //now i < 0 or nums[i] < nums[i+1]
        if (i >=0) {
            //go from right to left, find the first number nums[j] > nums[i]
            int j = n-1;
            while (nums[j] <= nums[i]) --j;
            //nums[j] > nums[i]
            swap(nums[j], nums[i]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};
