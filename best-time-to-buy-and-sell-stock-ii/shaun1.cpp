//shaun first sub, wrong answer, even with many fixes
//not a good idea, even after i switch from brute force recursion, still not good enough
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int bottom =-1, peak = -1; //price can not be negative, can be 0
        int profit = 0;
        for (int i = 0; i < n; ++i) {
            //can buy at 0 if right higher, i == 0 --> left higher
            bool leftH = (i ==0) || prices[i-1] > prices[i];
            bool rightH = (i+1 <= n-1) && prices[i] <= prices[i+1];
            if (leftH && rightH) {
                bottom = prices[i];
            }
            bool leftL = (i-1 >=0) && prices[i-1] <= prices[i];
            //can sell at n-1 if left lower, i==n-1, left lower
            bool rightL = (i == n-1) || prices[i] >= prices[i+1];
            if (leftL && rightL) {
                peak = prices[i];
            }
            
            if (peak >= 0 && bottom >= 0) {
                profit+= peak - bottom;
                peak = bottom = -1;
            }
        }
        return profit;
    }
};
//shaun tried to work out original buy low sell high idea, still wrong answer
class Solution0002 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        bool down = true; 
        int profit = 0, peak = -1, bottom = -1;
        for (int i = 1; i < n-1; ++i) {
            if (down && prices[i] < prices[i+1]) {
                bottom = prices[i]; //buy
                down = false; //up now
            }
            if (!down && prices[i] > prices[i+1]) {
                peak = prices[i];
                down = true;
            }
            if (peak && bottom) {
                profit += peak - bottom;
                peak = bottom = -1;
            }
        }
        return profit;
        
    }
};

//jz idea, record any gain you can see step by step
//runtime 8ms, faster than 99.40%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        for (int i = 1; i < n; ++i ) {
            if (prices[i] > prices[i-1]) profit += prices[i] - prices[i-1];
        }
        return profit;
    }
};

/*
idea 
input: array price at ith day
output: max profit, buy and sell multiple times
find low[i], lowest from 0 to i
at i maxProfit, how to get this? 

sell at all possibilities
sell at low[i] index+1 to i, find max, it is maxProfit[i]
how about next buy and sell? 
once you sell, low[i] will be from sell index + 1 
recursion ???

0 to i   i to n-1
res = INT_MAX
for (int i = 0; i < n; ++i)
    res = max(res,profit(0,i) + profit(i, n-1)
    
int profit(vi& prices, int left, int right) {
    if left == right return 0;
    if (left == right-1) {
        if (prices[left] < prices[right])
            return prices[right] - prices[left];
        else
            return 0;
    }
    for (int i )

}

not a good clean idea

buy at valley bottom, sell at peak
buy at V bottom, sell at ^ top
consider max at -1, and min at end+1
kind of greedy, correct? 
yes, all the gains, max it out
*/
