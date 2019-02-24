/*
Runtime: 8 ms, faster than 100.00% of C++ online submissions for Consecutive Numbers Sum.
Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Consecutive Numbers Sum.

idea from math 
https://blog.csdn.net/qq2667126427/article/details/80286645

*/
class Solution {
public:
    int consecutiveNumbersSum(int num) {
        int result = 0;
        for (int i = 0; i < num; ++i) {
            if (i * (i + 1) / 2 > num) {
                break;
            }
            int as = num - (i + 1) * i / 2;
            // 不能整除继续
            if (as % (i + 1) != 0)continue;
            // 开始的数字a大于0
            if (as / (i + 1) > 0){
                ++result;
            } 
        }

        return result;
    }
};

