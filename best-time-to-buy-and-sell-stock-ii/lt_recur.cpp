//shaun read lt recursion, TLE
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return calculate(prices, 0);
    }
private: 
    int calculate(vector<int>& prices, int s) {
        int n = prices.size();
        if (s >= n)
            return 0;
        int max = 0;
        for (int start = s; start < n; start++) {
            int maxprofit = 0; //max from s
            //try all selling point i: start+1 to n-1
            for (int i = start + 1; i < n; i++) {
                if (prices[start] < prices[i]) {
                    int profit = calculate(prices, i + 1) + prices[i] - prices[start];
                    if (profit > maxprofit)
                        maxprofit = profit;
                }
            }
            if (maxprofit > max)
                max = maxprofit; //max global
        }
        return max;
    }
};

