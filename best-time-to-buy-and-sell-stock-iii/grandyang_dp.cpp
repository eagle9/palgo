/*
grandyang dp, to understand
Runtime: 8 ms, faster than 100.00% of C++ online submissions for Best Time to Buy and Sell Stock III.
Memory Usage: 9.4 MB, less than 89.95% of C++ online submissions for Best Time to Buy and Sell Stock III.

*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int g[3] = {0};
        int l[3] = {0};
        for (int i = 0; i < prices.size() - 1; ++i) {
            int diff = prices[i + 1] - prices[i];
            for (int j = 2; j >= 1; --j) {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(l[j], g[j]);
            }
        }
        return g[2];
    }
};
