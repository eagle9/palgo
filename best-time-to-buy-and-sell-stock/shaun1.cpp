//shaun original idea, first sub accepted
//runtime 8ms, faster than 99%, memory less than 64%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> low(n); //lowest price from 0 to ith day
        int profit = 0;
        low[0] = prices[0];
        for (int i = 1; i < n; ++i) {
            low[i] = min(prices[i], low[i-1]);
            profit = max(prices[i] - low[i], profit);
        }
        return profit;
    }
};

/*idea
at most 1 transaction, no profit, 0
go from left to right, pi is price on dayi
apply dp
return max profit

dp[i] the max profit if sell at ith day
f[i] the min from 0 to i

*/
