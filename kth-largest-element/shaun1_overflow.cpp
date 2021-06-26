//shaun's idea to use partition, first sub stack overflow, not clear what's wrong

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n-1;
        return helper(nums,left,right,k);

    }
    
    int helper(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
        
        int i = partition(nums, left, right, nums[left]);
        //if (i - left+1 == k) return nums[i];
        // < pivot: left -- i-1, >= pivot: i -- right,   right-i+1 numbers
        //          1  --- i-left i-left+1
        //               k
        //                         k
        if (left + k-1 <= i) {
            return helper(nums, left, i, k);
        }else {
            return helper(nums, i+1, right, k-(i-left));
        }
    }
    //return first el index >= pivot
    //  left -- i-1 all < pivot,   i to right >= pivot
    int partition(vector<int>& nums, int left, int right, int pivot) {
        
        while (left < right) {
            while (nums[left] >= pivot && left < right) left++;
            while (nums[right] <= pivot && left < right) right--;
            if (left < right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        if (nums[left] >= pivot) return left;
        else return left;
    }

};

