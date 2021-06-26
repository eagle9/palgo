class Solution {
    //grandyang quick select idea, shaun translate to java, beats 34%
    public int findKthLargest(int[] nums, int k) {
        int left = 0, right = nums.length-1;
        while (true) {
            int pos = partition(nums, left, right);
            //0 to k-1,  pos stores the kth largest
            if (pos == k-1) return nums[pos];
            
            //cut range from right side
            else if (pos > k - 1) right = pos - 1;
            //pos < k-1, cut range from left side
            else left = pos + 1;
        }
    }
    int partition(int [] nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++;
                r--;
            }
            //descending order, left part >= pivot
            if (nums[l] >= pivot) l++;
            if (nums[r] <= pivot) r--;
        }
        //r < l
        //put pivot at r
        int temp = nums[left];
        nums[left] = nums[r];
        nums[r] = temp;
        return r;
    }
}


