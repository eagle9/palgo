//use hashmap to store smaller array, number and its count
//runtime 4ms, faster than 99.9%, mem less than 12%
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m; //number in 1 ---> need count from 2
        vector<int> res;
        
        for (auto a : nums1) ++m[a];
        for (auto a : nums2) {
            if (m[a]-- > 0) res.push_back(a);
        }
        return res;
    }
};
