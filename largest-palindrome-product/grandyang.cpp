/*
grandyang 
Runtime: 240 ms, faster than 89.66% of C++ online submissions for Largest Palindrome Product.
Memory Usage: 9 MB, less than 82.35% of C++ online submissions for Largest Palindrome Product.
*/
class Solution {
public:
    int largestPalindrome(int n) {
        int upper = pow(10, n) - 1, lower = upper / 10;
        for (int i = upper; i > lower; --i) {
            string t = to_string(i);
            long p = stol(t + string(t.rbegin(), t.rend()));
            for (long j = upper; j * j > p; --j) {
                if (p % j == 0) return p % 1337;
            }
        }
        return 9;
    }
};
