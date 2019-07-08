//shaun raw idea, but details checked with grandyang code
//you have to come up with longer permutations to find the rule
// 1 3 2
// 2 1 3  not a good sample to come up the rule
// 2 3 1  find 1, then find 2, swap them 
// 2 1 3  reverse 31 to 13

// 1 2 7 4 3 2 1
// 1 3 7 4 2 2 1  find 2, find 3, swap them
// 1 3 1 2 2 4 7  reverse 7 to 1
// idea, from left, find the max sub permu, go up then find down, say i, i is the candidate to make bigger
// want to replace i with a number j > i, of course from left again, swap  ij,
// since (j to tail] is max, j>i, now make (j to tail) min, makes sense
// 321 next is 123
// for this case, we can not find i, i ended -1
// but it simple this case, just reverse
// 3421
// 4321 find 3, then 4, swap them 
// 4123     obviously, (4 tail) to min
//

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
