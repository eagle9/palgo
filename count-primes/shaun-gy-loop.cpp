//shaun still remember the cross off multiple idea
// how to code, we need vector<bool> prime(n), then loop from first prime number 2
//so we set up a loop i from 2 to n, then i's multiple j from 2 to i*j <=n, prime[i*j] = false
//why 1 pass loop i works?  only need to cross prime number's multiple
//runtime 88ms, faster than 36%, mem less than 80%
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> prime(n, true);
        for (int i = 2; i < n; ++i) {
            if (prime[i]) {
                ++res;
                for (int j = 2; i * j <= n; ++j) {
                    prime[i * j] = false;
                }
            }
        }
        return res;
    }
};
