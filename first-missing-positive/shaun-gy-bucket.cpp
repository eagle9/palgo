//grandyang idea2, 0ms, faster than 100%, mem less than 99.9%
//shaun read and understand, bucket sorting, number to its bucket according to its value, in range
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            //if nums[i] in [0,n]: nums[i] to be stored in at index nums[i]-1
            //key point here is to do this with a while loop
            while (nums[i] > 0 && nums[i] <= n &&  nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                //nums[i] changed here
                //this loop keep to put nums[i] into its correct bucket 
                //exit when its out of [0,n] range or correct bucket
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        //found 1 to n present
        return n + 1;
    }
};
