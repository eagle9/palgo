// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

//http://www.cnblogs.com/grandyang/p/5666502.html
//Your submission beats 51.60% Submissions!
//这道题是一道典型的猜价格的问题，根据对方说高了还是低了来缩小范围，最简单快速的方法就是折半搜索法，原理很简单，
class Solution {
public:
    int guessNumber(int n) {
        if (guess(n) == 0) return n;
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2, t = guess(mid);
            if (t == 0) return mid;
            else if (t == 1) left = mid;
            else right = mid;
        }
        return left;
    }
};
