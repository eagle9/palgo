/*
grandyang 1, 
Runtime: 8 ms, faster than 100.00% of C++ online submissions for Subsets II.
Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Subsets II.
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        if (S.empty()) return {};
        vector<vector<int>> res(1);
        sort(S.begin(), S.end());
        int size = 1, last = S[0];
        for (int i = 0; i < S.size(); ++i) {
            if (last != S[i]) {
                last = S[i];
                size = res.size();
            }
            int newSize = res.size();
            for (int j = newSize - size; j < newSize; ++j) {
                res.push_back(res[j]);
                res.back().push_back(S[i]);
            }
        }
        return res;
    }
};

