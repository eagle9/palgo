//grandyang binary search and sort, shaun read and understand
//time nlogn
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
        sort(nums2.begin(), nums2.end());
        //check each number in nums1 if it is in nums2 using binary search
        for (auto a : nums1) {
            if (binarySearch(nums2, a)) {
                res.insert(a);
            }
        }
        //convert the res set into vector
        return vector<int>(res.begin(), res.end());
    }
    bool binarySearch(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};
