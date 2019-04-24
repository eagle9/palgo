//reverse direction two pointers jz, shaun code from the idea, accepted after debugging
//beats 72% submissions
class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        if (nums.empty()) return 0;
        int n = nums.size();
        
        int left = 0, right = n-1;
        while (left < right) {
            while (nums[left] < k && left < right) left++; 
            while (nums[right] >= k && left < right) right--;
            if (left < right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        // right == left now, linhuchong treatment, pretty smart
        if (nums[left] < k) return left+1;
        else return left;
    }
};
