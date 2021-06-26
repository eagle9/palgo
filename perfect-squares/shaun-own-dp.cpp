/*
shaun 2nd own idea, with a search of ideas
accepted after 2 bug fixes
runtime 84ms, faster than 69%, mem less than 59%
f(n) with f(n-1), no way, change directions 
for n, the least number of perfect square numbers that sum to n
n - 1, n - 4, n - 9, ...
then f(n) = 1+ min  f(n- k^2), k = 1 to k*k < n
n = 1,  f(n) = 1
n = 2, f(n) = 2
n= 3, f(3) = 1+ min(f(3-1)) = 1 + 2 = 3

testing: 
n= 12
f(12): 2+1 = 3
    f(11):?  
    f(8): 2
      f(7):
        f(6):
        f(3):
      f(4): 1
        f(3): 3
        f(0): 0
    f(3): ?
      1+f(2) = 3
*/    

class Solution {
public:
    int numSquares(int n) {
        if (n == 1) return 1;
        vector<int> f(n+1, INT_MAX);  //bug 1-- init with 0 wrong, since look for min, so init with INT_MAX
        f[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            //f[i] = INTMAX;
            for (int k = 1; k*k <= i; ++k) { //k*k <= n --> k*k <= i
                f[i] = min(f[i], f[i - k*k]);
            }
            f[i]++;
        }
        return f[n];
    }
};
