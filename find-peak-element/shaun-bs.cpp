//shaun's own idea and code, accepted after fixing compile error caused by typo
//runtime 8ms, faster than 99%, mem less than 100%
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left +1 < right) {
			//       mid                     mid+1    mid-1      ?
			// mid-1     mid+1           mid                mid  
			//                     mid-1                         ?
            int mid = left + (right - left)/2;
            if (isPeak(nums, mid)) return mid; //case 1, bingo at mid, draw a pic with all possibilites 

			//case 2: mid - 1 < mid < mid+1, go right part
            if ((mid-1 < 0|| nums[mid-1] < nums[mid]) && (mid+1<n && nums[mid] < nums[mid+1])) left = mid;

			//case 3&4: mid-1 > mid ? mid+1, go left part 
            else if (mid-1>=0 && nums[mid-1] > nums[mid]) right = mid; 
        }
        if (isPeak(nums, left)) return left;
        else return right;
    }
private: 
    bool isPeak(vector<int>& nums, int mid) {
        if ((mid-1 < 0|| nums[mid-1] < nums[mid]) && (mid+1 ==nums.size() || nums[mid] > nums[mid+1])) return true;
        else return false;
    }
};
