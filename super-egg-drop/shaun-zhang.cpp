/*naive 2d dp

https://zhanghuimeng.github.io/post/leetcode-887-super-egg-drop/
https://www.cnblogs.com/Phantom01/p/9490508.html

dp[n][k] 表示用k个鸡蛋测n层最少需要多少步。
我们可以枚举第一次在第i层扔鸡蛋，会得到两种结果:

鸡蛋坏掉: 我们接下来需要面对的情形是: 用 k-1 个鸡蛋来测量 i-1 层，所以最少需要 dp[i-1][k-1] 步。
鸡蛋没坏: 我们接下来要面对的情形是: 用 k 个鸡蛋来测量 n-i 层，所以最少需要 dp[n-i][k] 步。
因为我们总会面对最坏情况，所以，在第i层扔，会用 max(dp[i-1][k-1], dp[n-i][k]) + 1 步。
所以我们的递推式如下:
dp[n][k] = min{ max(dp[i-1][k-1], dp[n-i][k]) + 1 } (1 <= i <= n)

TLE
*/
class Solution1 {
public:
    int superEggDrop(int K, int N) {
        int f[N + 1][K + 1];
        for (int i = 0; i <= K; i++) {
            f[0][i] = 0;  // zero floor, no need to check
            f[1][i] = 1;  // one floor, check once
        }
        for (int i = 0; i <= N; i++) {
            f[i][1] = i;  // one egg checks all floors
            f[i][0] = 0;  // no egg to check
        }

        for (int i = 2; i <= N; i++) {
            for (int j = 2; j <= K; j++) {
                f[i][j] = INT_MAX;
                for (int k = 1; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[i - k][j], f[k - 1][j - 1]) + 1);
                }
            }
        }
        return f[N][K];
    }
};

//2d dp with binary search
//runtime 156ms, faster than 16%, mem less than 71%
class Solution2 {
public:
    int superEggDrop(int K, int N) {
        int f[N + 1][K + 1];
        for (int i = 0; i <= K; i++) {
            f[0][i] = 0;  // zero floor, no need to check
            f[1][i] = 1;  // one floor, check once
        }
        for (int i = 0; i <= N; i++) {
            f[i][1] = i;  // one egg checks all floors
            f[i][0] = 0;  // no egg to check
        }
        
        for (int i = 2; i <= N; i++) {
            for (int j = 2; j <= K; j++) {
                f[i][j] = INT_MAX;
                
                // 注意边界条件
                int left = 1, right = i;
                while (left + 1 < right) {
                    int mid = (left + right) / 2;
                    if (f[i - mid][j] < f[mid - 1][j - 1])
                        right = mid;
                    else if (f[i - mid][j] > f[mid - 1][j - 1])
                        left = mid;
                    else
                        left = right = mid;
                }
                f[i][j] = min(max(f[right - 1][j - 1], f[i - right][j]), max(f[left - 1][j - 1], f[i - left][j])) + 1;
            }
        }
        return f[N][K];
    }
};

//phantom01
//runtime 4ms, faster than 85%, mem less than 57%
class Solution {
public:
    int superEggDrop(int K, int N) {

        int dp[N+2][K+2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        for (int m = 1; m <= N; m++) {
            dp[m][0] = 0;
            for (int k = 1; k <= K; k++) {
                dp[m][k] = dp[m-1][k] + dp[m-1][k-1] + 1;
                if (dp[m][k] >= N) {
                    return m;
                }
            }
        }
        return N;
    }
};
