//use jz template
//runtime 8ms, faster than 95%, mem less than 52%
//cutting idea, to find the first == target, go to lower: right = mid
//                          nums[mid] < target, go to lower: right = mid
//                          nums[mid] > target, go to higher: left = mid+1
class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res(2,-1);
        if (nums.empty()) return res;
            
        int left = 0, right = nums.size()-1;
        while (left +1 < right) {
            int mid = left + (right - left)/2;
            if (target <= nums[mid]) { //when == squeeze to the left
                right = mid;
            }else { // nums[mid] < target, sqeeze to the right
                left = mid+1;
            }
        }
        
        //left right next to each other and in bound
        if (nums[left] == target) res[0] = left; //find first, check left first
        else if (nums[right] == target) res[0] = right; //else is key here, nums[left] can == nums[right], this case take left
        
        left = 0;right = nums.size()-1;
        while (left +1 < right) {
            int mid = left + (right-left)/2;
            if (target < nums[mid]) {
                right = mid-1;
            }else { //nums[mid] <= target when ==, squeeze to the right to find the last
                left = mid;
            }
        }
        //loop exit: left right next to each other and in bound
        if (nums[right] == target) res[1] = right;//find last, check right first
        else if (nums[left] == target) res[1] = left; 
        
        
        return res;
    }
};

//gy, hua template, 
//runtime 8ms, faster than 90%, mem less than 93%
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res(2,-1);
        if (nums.empty()) return res;
            
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (target <= nums[mid]) { //when == go the left side, to find first
                right = mid;
            }else { // nums[mid] < target, simply go right half
                left = mid+1;
            }
        }
        //left == right now
        if (nums[right] == target) res[0] = right;
        
        
        left = 0;right = nums.size()-1;
        //we have to use left+1< right here, since when == target, to find last, we have to go right: left = mid, now ==, we can not do left = mid+1
        
        while (left +1 < right) { 
            int mid = left + (right-left)/2;
            if (target < nums[mid]) {
                right = mid-1;
            }else { //nums[mid] <= target when ==, go to right half, to find the last
                left = mid;
            }
        }
        //loop exit: left right next to each other and in bound
        if (nums[right] == target) res[1] = right;//find last, check right first
        else if (nums[left] == target) res[1] = left; 
        
        
        return res;
    }
};

//use donglin's template
//runtime 4ms, faster than 99.9%, mem less than 66%
class Solution3 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res(2,-1);
        if (nums.empty()) return res;
            
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (target <= nums[mid]) {
                right = mid-1;
            }else { // nums[mid] < target
                left = mid+1;
            }
        }
        
        //right left
        if (left != nums.size() && nums[left] == target) res[0] = left;
        
        left = 0;right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (target < nums[mid]) {
                right = mid-1;
            }else { //nums[mid] <= target
                left = mid + 1;
            }
        }
        //right left, target < all,  right, left=0
        if (right != -1 && nums[right] == target) res[1] = right;
        return res;
    }
};
