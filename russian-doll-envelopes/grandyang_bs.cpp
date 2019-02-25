/*
binary search grandyang, to understand and write yourself from memory
Runtime: 28 ms, faster than 100.00% of C++ online submissions for Russian Doll Envelopes.
Memory Usage: 11.5 MB, less than 85.71% of C++ online submissions for Russian Doll Envelopes.

*/
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        vector<int> dp;
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        for (int i = 0; i < envelopes.size(); ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
            if (it == dp.end()) dp.push_back(envelopes[i].second);
            else *it = envelopes[i].second;
        }
        return dp.size();
    }
};
