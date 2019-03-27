//shaun's original idea, solution, accepted, beats 29%, accepted first sub (after adding empty check)
class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int findPosition(vector<int> &nums, int target) {
        if (nums.empty()) return -1;
        
        int left = 0, right = nums.size()-1;
        
        while (left+1 < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] < target) { // mid -- right
                left = mid + 1;
            }else if (nums[mid] == target) {
                return mid;
            }else { //nums[mid] > target ===> left --- mid
                right = mid-1;
            }
        }
        //now left +1 >= right
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        return -1;
    }
};

//shaun updated with check to jz solution, beats 17%
class Solution2 {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int findPosition(vector<int> &nums, int target) {
        if (nums.empty()) return -1;
        
        int left = 0, right = nums.size()-1;
        
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] < target) { // mid -- right
                left = mid + 1;
            }else if (nums[mid] == target) {
                return mid;
            }else { //nums[mid] > target ===> left --- mid
                right = mid-1;
            }
        }
        //left == right
        if (nums[left] == target) return left;
        return -1;
    }
};
