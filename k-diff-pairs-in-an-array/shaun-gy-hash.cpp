//grandyang hash idea
//understood, cutting: similar to two sum with hash, only +k, no need to check -k
//runtime 44ms, faster than 49%, mem less than 20%
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        unordered_map<int, int> m;
        for (int num : nums) ++m[num];
        for (auto a : m) {
            //critical to deal with k ==0 cases separately
            if (k == 0 && a.second > 1) ++res;
            if (k > 0 && m.count(a.first + k)) ++res;
        }
        return res;
    }
};
