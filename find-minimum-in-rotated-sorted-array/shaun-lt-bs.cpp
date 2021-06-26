//shaun lt binary search, cutting: draw a picture
//runtime 4ms, faster than 79%, mem less than 58%
class Solution {
public:
    int findMin(vector<int>& nums) {
        int N = nums.size();
        int left = 0, right = N - 1;
        //sorted array case
        if (nums[left] < nums[right]) return nums[left];
        
        // > 1 because left = mid, can not be mid+1
        while(right - left > 1){
            int mid = left + (right-left)/ 2;
            if (nums[mid] < nums[left])
                right = mid;
            else
                left = mid;
        }
        //return nums[left];
        //left right next to each other
        return min(nums[left], nums[right]);
    }
};
