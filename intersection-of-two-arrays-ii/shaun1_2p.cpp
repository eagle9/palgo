//two pointers, suitable for two arrays are already sorted. 
//another advantage of 2 pointers is less memory. So when both arrays are too big to fit into memory, 2 pointers method is still useful.
//just do external sorting to both arrays, then read each array chunk by chunk
//runtime 8ms, faster than 96.82%, mem less than 78%
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i; ++j;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                ++i;
            }
        }
        return res;
    }
};
