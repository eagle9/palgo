/*
 /
/
   /
  /
left pivot right
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int n  = nums.size();
        int left = 0, right = n-1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] < nums[mid]) { //mid in first half sorted from left to pivot
                // situation 1, red line
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid;
                }
            } else { // mid in second half from pivot to right
                // situation 2, green line
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
        } // while
        
        //left + 1 = right
        if (nums[left] == target) {
            return left;
        }
        if (nums[right] == target) {
            return right;
        }
        return -1;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int n  = nums.size();
        int left = 0, right = n-1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            //where is mid? 
            if (nums[mid] >= nums[left]) { // left mid max
                if (nums[left] <= target && target < nums[mid]) right = mid;
                else left = mid;
            }else { // min   mid right
                if (nums[mid] < target && target <= nums[right]) left = mid;
                else right = mid;
            }
        }
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        return -1;
    }
};

//shaun own idea and code, wrong answer first several subs
class Solution3 {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int n  = nums.size();
        int left = 0, right = n-1;
        while (left + 1 < right) {
        	int mid = left + (right - left)/2;
            
        	if (target < nums[right]) {
                if (target < nums[mid])
                    right = mid;
                else if (nums[mid] < target)
                    left = mid;
                else return mid;
                    
            }
            else if (target == nums[right]) return right;
            else if (target == nums[left]) return left;
            else  {// target > nums[left]
                if (target < nums[mid]) right = mid;
                else if (nums[mid] < target) left = mid;
                else return mid;
            }
        	

        }
        //left right
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        return -1;
    }
};

