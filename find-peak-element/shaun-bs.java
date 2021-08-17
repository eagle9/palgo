class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        int left = 0, right = n - 1;
        while (left +1 < right) {
			//       mid                     mid+1    mid-1      ?
			// mid-1     mid+1           mid                mid  
			//                     mid-1                         ?
            int mid = left + (right - left)/2;
            if (isPeak(nums, mid)) return mid; //case 1, bingo at mid, draw a pic with all possibilites 

			//case 2: mid - 1 < mid < mid+1, go right part
            if ((mid-1 < 0|| nums[mid-1] < nums[mid]) && (mid+1<n && nums[mid] < nums[mid+1])) left = mid;

			//case 3&4: mid-1 > mid ?(no matter) mid+1, go left part 
            else if (mid-1>=0 && nums[mid-1] > nums[mid]) right = mid; 
        }
        if (isPeak(nums, left)) return left;
        else return right;
    }


    boolean isPeak(int [] nums, int mid) {
        //left < mid > right
        if ((mid-1 < 0|| nums[mid-1] < nums[mid]) 
            && (mid+1 ==nums.length || nums[mid] > nums[mid+1])) return true;
        else return false;
    }
}
