/*
Runtime: 44 ms, faster than 28.00% of C++ online submissions for Wiggle Sort.
Memory Usage: 6 MB, less than 0.30% of C++ online submissions for Wiggle Sort.
grandyang sort and wiggle idea
shaun cpp code, to code the for loop, you have to write numbers on papper and be strict
Runtime: 44 ms, faster than 28.00% of C++ online submissions for Wiggle Sort.
Memory Usage: 6 MB, less than 0.30% of C++ online submissions for Wiggle Sort.
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        //start from 2 is cleaner since it is easy to determine the end
        for (int i = 2; i <= n-1; i+=2) {
            swap(nums[i], nums[i-1]);
        }
    }
};
