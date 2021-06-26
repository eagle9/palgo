//jz quick select divide and conquer
//runtime 19ms, faster than 37%, mem less than 94%
class Solution1 {
    public int findKthLargest(int[] nums, int k) {
            return quickSelect(nums, 0, nums.length - 1, k);
    }

    private int quickSelect(int[] nums, int left, int right, int k) {
        if (left <= right) {
            int p = partion(nums, left, right);
            if (p == nums.length - k)
                return nums[p];
            
            else if (p > nums.length - k)
                return quickSelect(nums, left, p - 1, k);
            else
                return quickSelect(nums, p + 1, right, k);
        }
        return -1;
    }
    //             k                 1
    // left <   pivot < pivot+1   len-1 . ===> k + pivot = 1 +len -1 = len
    //          len - k ---> bingo
    //  len-k            ---> look in left pivot-1
    //                 len-k  ---> look in pivot+1 to right
    private  int partion(int[] nums, int left, int right) {
        //take left as pivot index
        int i = left + 1, j = right;
        while (i <= j) {
            while (i <= right && nums[i] < nums[left])
                i++;
            while (j >= left + 1 && nums[j] > nums[left])
                j--;
            //if (i > j) break;  for while true
            if (i <= j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
        int temp = nums[left];
        nums[left] = nums[j];
        nums[j] = temp;
        return j;
    }
    
}

//shaun modified jz quickselect, partition left > pivot > right, to align better
//                                          0      k-1 --->kth largest
//runtime 28ms, faster than 33%, mem less than 84%
class Solution {
    public int findKthLargest(int[] nums, int k) {
            return quickSelect(nums, 0, nums.length - 1, k);
    }

    private int quickSelect(int[] nums, int left, int right, int k) {
        if (left <= right) {
            int p = partion(nums, left, right);
            if (p ==  k-1)
                return nums[p];
            
            else if (p >  k-1)
                return quickSelect(nums, left, p - 1, k);
            else
                return quickSelect(nums, p + 1, right, k);
        }
        return -1;
    }
    //  1      k ------> bingo               
    // 0 >   pivot >    len-1 
    //     k    ---  left to pivot-1
    //             k ---->  pivot+1 to right
    private  int partion(int[] nums, int left, int right) {
        //take left as pivot index
        int i = left + 1, j = right;
        while (i <= j) {
            while (i <= right && nums[i] > nums[left])
                i++;
            while (j >= left + 1 && nums[j] < nums[left])
                j--;
            //if (i > j) break;  for while true
            if (i <= j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
        int temp = nums[left];
        nums[left] = nums[j];
        nums[j] = temp;
        return j;
    }
    
}
