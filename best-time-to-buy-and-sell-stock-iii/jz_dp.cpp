//jz dp class idea v1, runtime 16ms, faster than 28%, memory less than 5%
//to deep read and able to write from idea memory
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int K = 2;
        int n = prices.size();
        int i, j, k;
        
        vector<vector<int>> f(n+1, vector<int>(2*K+1+1, INT_MIN));
        
        f[0][1] = 0;
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= 2 * K + 1; j += 2) {
                f[i][j] = update(f[i][j], f[i-1][j], 0);
                if (j > 1 && i > 1) f[i][j] = update(f[i][j], f[i - 1][j - 1], prices[i - 1] - prices[i - 2]);
            }
            
            for (j = 2; j <= 2 * K; j += 2) {
                if (i > 1) f[i][j] = update(f[i][j], f[i-1][j], prices[i - 1] - prices[i - 2]);
                if (j > 1) f[i][j] = update(f[i][j], f[i-1][j-1], 0);
            }
        }
        
        int res = INT_MIN;
        for (j = 1; j <= 2 * K + 1; j += 2) {
            res = update(res, f[n][j], 0);
        }
        
        return res;
    }
private:
	//update a with b+delta when b is not INT_MAX
    int update(int a, int b, int delta) {
        if (b == INT_MIN) return a;
        if (b + delta > a) return b + delta;
        return a;
    } 
};
