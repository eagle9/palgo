//shaun's own idea, use hashset directly, time = O(n), space = O(n)
//runtime 8ms, faster than 99.85%, mem less than 22%
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, res;
        for (int x: nums1) set1.insert(x);
        for (int x: nums2) {
            if (set1.count(x)) res.insert(x);
        }
        return vector<int>(res.begin(), res.end());
    }
};
