//shaun valley peak idea, checked with lt code, runtime 8ms, faster than 99%, memory less than 50%
class Solution {
public:
        int maxProfit(vector<int> & prices) {
        if (prices.empty()) return 0;
        
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        int i = 0, n = prices.size();
        while (i < n - 1) {
            //go down when you can
            while (i < n - 1 && prices[i] >= prices[i + 1])
                i++;
            //can not going down further, valley reached
            valley = prices[i];
            //go up when you can
            while (i < n-1 && prices[i] <= prices[i + 1])
                i++;
            //can not going up further, peak
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
};
