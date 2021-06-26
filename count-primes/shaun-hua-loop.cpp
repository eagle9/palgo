//hua's idea, similar to gy and shaun's 
//implementation is faster using vector<unsigned char> rather than vector<bool>
//runtime 24ms, faster than 91%, mem less than 19%
class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        
        vector<unsigned char> prime(n+1, 1);
        //vector<bool> prime(n,true);
        
        prime[0] = prime[1] = 0;
        int ans = 0;
        //for(int i=2;i<=sqrt(n);++i) {
        for(int i=2;i<n;++i) {
            if (prime[i]) {
                ans++;
                for(int j=2;j*i<n;++j) prime[i*j] = 0; //prime[i*j] = false;
            }
        }
        
        //int ans = accumulate(prime.begin(), prime.end(), 0);
        return ans;
    }
};

