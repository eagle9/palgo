//brute force, cutting angle, try every possible start of consecutive number series
//time O(n^2), space O(1)
class Solution00 {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0;
        for (int start = 1; start <= N; ++start) {
            int target = N, x = start;
            while (target > 0) {
                target -= x++;
            }
            if (target == 0) ans++;
        }
        return ans;
    }
};
//naive use math, TLE, time O(N)
class Solution11 {
public:
    int consecutiveNumbersSum(int N) {
        // 1 + 2 + ... +k = (1+k)*k/2 = N ---> (1+k)*k = 2N
        // start from x   (1+k)*k/2 + kx == N??
        // kx = N - (1+k)*k/2
        // 2x = 2N/k - (1+k) ----> 2N % k == 0, and 2N/k - 1 -k % 2 == 0
        // 1 + 2 + ..  +y = (1+y)*y/2 
        // 2N = k(2x + k + 1)
        int ans = 0;
        for (int k = 1; k <= 2*N; ++k)
            if (2 * N % k == 0) {
                int y = 2 * N / k - k - 1;
                if (y % 2 == 0 && y >= 0)
                    ans++;
            }
        return ans;
    }
};

//runtime 4ms, faster than 93%, mem less than 54%
//O(sqrt(N))
// k(2x+k+1) == 2N,   k <= sqrt(2N)
class Solution{
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0;
        for (int k = 1; k <= (int) sqrt(2 * N); ++k) {
            if ((2 * N % k) != 0) continue;
            int y = 2 *N / k - k - 1;
            if (y % 2 == 0 && y >= 0) {
                ans++;
            }
        }
        return ans;
    }
};
