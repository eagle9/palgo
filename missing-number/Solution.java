//jz, using math sum from 0 to n, beats 71%
//grandyang idea1
class Solution1 {
    public int missingNumber(int[] nums) {
        int len = nums.length;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
        }
        //0, 1, 2,...,len, total len+1 numberï¼Œone extra number == len
        int targetsum = len * (len + 1) / 2;
        return targetsum - sum; 
    }
}

//grandyang idea2, using bit operation
//0 1 3, n = 3
//0 1 2 3 
//remember go over the basic test cases
//beats 71%
class Solution2 {
    public int missingNumber(int [] nums) {
        int n = nums.length;
        int res = 0;
        for (int i = 0; i < n; i++) {
            res ^= nums[i]; //bit and
        }
        //key point: i <= n
        for (int i = 0; i <= n; i++) {
            res ^= i;
        }
        return res;
    }
}

//when it is sorted, time is logn
//0 1 3
//left = 0, right=2
//mid = 0 + 1 = 1, nums[mid] = 1
//left = 2, right = 2
//loop exit, 
class Solution3 {
    //
     //using sort and binary search, find the first A[i] != i. beats 12%
     //time complexity is n(logn ) because of the sorting
    public int missingNumber(int[] nums) {
        
        Arrays.sort(nums);
        int left = 0, right = nums.length - 1;
        //while (left +1 < right) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            //compare nums[mid] and mid
            if (nums[mid] > mid) { //0 1 ... mid, missing from left to mid, larger number moved to left
                //right = mid;
                right = mid - 1;
            }
            else { //nums[mid] <= mid, missing from mid to right
                //left = mid;
                left = mid + 1;
            }
        }
        return nums[left] == left ? left + 1 : left;
    }


}


//when it is sorted, time is logn
//0 1 3
//left = 0, right=2
//mid = 0 + 1 = 1, nums[mid] = 1, missing mid to right
//
//left = 1, right = 2
//1 3
//loop exit, 
class Solution {
    //
     //using sort and binary search, find the first A[i] != i. beats 12%
     //time complexity is n(logn ) because of the sorting
    public int missingNumber(int[] nums) {
        
        Arrays.sort(nums);
        int left = 0, right = nums.length - 1;
        while (left +1 < right) {
        
            int mid = left + (right - left) / 2;
            //compare nums[mid] and mid
            if (nums[mid] > mid) { //0 1 ... mid, missing from left to mid, larger number moved to left
                right = mid;
                
            }
            else { //nums[mid] <= mid, missing from mid to right
                //left = mid;
                left = mid;
            }
        }
        //left, right
        if (nums[left] != left) return left;
        if (nums[right] != right) return right;
        return right+1;
    }
}
