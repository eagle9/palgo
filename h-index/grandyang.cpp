/*
Runtime: 8 ms, faster than 100.00% of C++ online submissions for H-Index.
Memory Usage: 9.3 MB, less than 1.62% of C++ online submissions for H-Index.
grandyang idea and c++
not fully understand. the problem h index concept is not easy to get right

*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int n = citations.size();
        for (int i = 0; i < n; ++i) {
            if (i >= citations[i]) return i;
        }
        return n;
    }
};
