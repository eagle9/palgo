//shaun code from grandyang bs idea, runtime 40ms, faster than 92%, mem less than 82%
//the idea is to apply Longest increasing subsequence idea
//reduce the 2d to 1d, first increasing order, when first ties, second greater in front, this way, larger second will enter vdp first, then replaced by smaller second
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) return 0; //key to add
        struct eCompare {
            bool operator () (const pair<int,int>&a, const pair<int,int>&b) const {
                if (a.first == b.first) return a.second > b.second;
                return a.first < b.first;
            }
        };
        sort(envelopes.begin(), envelopes.end(), eCompare());
        vector<int> v{envelopes[0].second};
        
        for (pair<int,int> e: envelopes) {
            //find first it >= e.second
            auto it = lower_bound(v.begin(), v.end(), e.second);
            if (it == v.end()) v.push_back(e.second);
            else *it = e.second;
        }
        return v.size();
    }
};
