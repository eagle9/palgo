//shaun tried 1 idea, wrong answer, failed case [10,1,10,10,10]
class Solution000 {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int n = nums.size();
        if (n == 1) return nums[0];
        if (nums[left] < nums[right]) return nums[left]; //have to add this case
        while (left + 1 < right) {
            int mid = left + (right - left)/2;
            //where is mid? 
            
            if (nums[left] < nums[mid]) { // left mid max
                left = mid;
            }else if (nums[left] > nums[mid]){  //  min mid right
                right = mid;
            }else { // nums[mid] == nums[left]
                left++;
            }
        }
        return min(nums[left], nums[right]);
    }
};

//tried to apply 1 idea to 2, with reference to grandyang
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int n = nums.size();
        if (n == 1) return nums[0];
        if (nums[left] < nums[right]) return nums[left]; //have to add this case
        int res = INT_MAX;
        while (left+1 < right) {
            int mid = left + (right - left)/2;
            
            //where is mid? 
            
            if (nums[left] < nums[mid]) { // left mid max
                res = min(res, nums[left]);
                left = mid;
            }else if (nums[left] > nums[mid]){  //  min mid right
                res = min(res,nums[right]);
                right = mid;
            }else { // nums[mid] == nums[left]
                left++;
            }
        }
        return min(res,min(nums[left], nums[right]));
    }
};
