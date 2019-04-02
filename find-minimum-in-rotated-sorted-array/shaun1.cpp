//first sub wrong answer, showed the case that triggring wrong answer
//added code to deal with no rotation case, accepted
//runtime 4ms, faster than 100%, mem less than 84%
class Solution {
public:
    int findMin(vector<int>& nums) {
        //nums not empty 
        if (nums.size() == 1) return nums[0];
        
        int left = 0, right = nums.size()-1;
        
        if (nums[left] < nums[right]) return nums[left];
        
        while (left+1 < right) {
            int mid = left + (right - left)/2;
            if (nums[left] <= nums[mid] )
                left = mid;
            else if (nums[mid] <= nums[right] )
                right = mid;
        }
        return min(nums[left], nums[right]);
    }
};
