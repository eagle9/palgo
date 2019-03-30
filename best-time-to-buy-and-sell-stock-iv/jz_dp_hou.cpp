//jz dp class idea buy sell states
//understand now, check comments and idea
//runtime 16ms, faster than 28%, memory less than 5%
class Solution1 {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        if (k > n/2) { // trade as many times as possible
            int sum = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i-1]) sum += prices[i] - prices[i-1]; //greedy
            }
            return sum;
        };
        
        vector<vector<int>> f(n+1, vector<int>(2*k+1+1));
        f[0][1] = 0;
        for (int j = 2; j <=2*k+1; ++j) f[0][j] = INT_MIN; //Integer.MIN_VALUE;
        for (int i = 1; i <= n; ++i) {
            //stage 1, 3 ,5, no stock held
            //yesterday j -> today j, i means day0 to dayi-1, value change = 0
            //yesterday j-1-> today j=> means sold today(i-1th day), value change
            //f[i][j] = max{f[i-1][j], f[i-1][j-1] + Pi-1 – Pi-2}
            for (int j = 1; j <= 2*k+1; j+=2) {
                f[i][j] = f[i-1][j];
                if (i>=2 && j > 1 && f[i-1][j-1] != INT_MIN)
                    f[i][j] = max(f[i][j], f[i-1][j-1] + prices[i-1] - prices[i-2]); //Math.max in java
            }
            //stage 2,4,...,2K, have stock
            //yesterday j -> today j, value change = p[i-1]-p[i-2]
            //yesterday j-1 -> today j, value change = 0
            //f[i][j] = max{f[i-1][j] + Pi-1 – Pi-2, f[i-1][j-1]}
            for (int j = 2; j <= 2*k; j+=2) {
                f[i][j] = f[i-1][j-1]; 
                if (i >= 2 && f[i-1][j]!= INT_MIN)
                    f[i][j] = max(f[i][j], f[i-1][j] + prices[i-1] - prices[i-2] );
            }
        }
        int res = f[n][1];
        for (int i =3; i <= 2*k+1; i+=2) res = max(res,f[n][i]);
        return res;
    }
}; //c++ required

//shaun try rolling array to reduce dimension and space usage
//accepted first sub, runtime 12ms, faster than 53%, memory less than 57%
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        if (k > n/2) { // trade as many times as possible
            int sum = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i-1]) sum += prices[i] - prices[i-1]; //greedy
            }
            return sum;
        };
        vector<vector<int>> f(2, vector<int>(2*k+1+1));
        f[0][1] = 0;
        for (int j = 2; j <=2*k+1; ++j) f[0][j] = INT_MIN; //Integer.MIN_VALUE;
        int prev = 0, cur = 1;
        for (int i = 1; i <= n; ++i) {
            //stage 1, 3 ,5, no stock held
            //yesterday j -> today j, i means day0 to dayi-1, value change = 0
            //yesterday j-1-> today j=> means sold today(i-1th day), value change
            //f[i][j] = max{f[i-1][j], f[i-1][j-1] + Pi-1 – Pi-2}
            for (int j = 1; j <= 2*k+1; j+=2) {
                f[cur][j] = f[prev][j];
                if (i>=2 && j > 1 && f[prev][j-1] != INT_MIN)
                    f[cur][j] = max(f[cur][j], f[prev][j-1] + prices[i-1] - prices[i-2]); //Math.max in java
            }
            //stage 2,4,...,2K, have stock
            //yesterday j -> today j, value change = p[i-1]-p[i-2]
            //yesterday j-1 -> today j, value change = 0
            //f[i][j] = max{f[i-1][j] + Pi-1 – Pi-2, f[i-1][j-1]}
            for (int j = 2; j <= 2*k; j+=2) {
                f[cur][j] = f[prev][j-1]; 
                if (i >= 2 && f[prev][j]!= INT_MIN)
                    f[cur][j] = max(f[cur][j], f[prev][j] + prices[i-1] - prices[i-2] );
            }
            swap(prev,cur); //java no swap, have to write yourself
        }
        int res = f[prev][1];
        for (int i =3; i <= 2*k+1; i+=2) res = max(res,f[prev][i]);
        return res;
    }
}; //c++ required

/*jz dp idea

f[i][j] max profit ith day (from 1) at state j = 1 to 5
i --- first i days, day 0  to day i-1
j is state that stands for how many times stock has beent traded
1 -- no stock 
2 -- have stock 1st time
3 -- sold stock 1st time
4 -- have stock 2nd time
5 -- sold stock 2nd time

recurrence equations, try to calculate profit with diff with consecutive days
check comments for more details
*/
