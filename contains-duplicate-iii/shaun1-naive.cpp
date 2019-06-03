//brute force naive,  laioffer. more natural than lt version
class Solution1 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for (int i = 0; i < nums.size(); ++i) {
            //from i-k to i
            for (int j = i+1; j < nums.size() && j-i<=k ; ++j) {
                if (abs((long)nums[i] - (long)nums[j]) <= t) return true;
            }
        }
        return false;
    }
};

//lt naive brute force, TLE
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = max(i - k, 0); j < i; ++j) {
                if (abs((long)nums[i] - (long)nums[j]) <= t) return true;
            }
        }
        return false;
    }
};
