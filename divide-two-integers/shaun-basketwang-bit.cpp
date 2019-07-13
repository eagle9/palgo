//basketwang idea, cutting ---using shift to double divisor and compare with dividend

/*
https://www.youtube.com/watch?v=uD1Cw1JbD8E
example:
32/3
   3<< 1  --- 6
   3<< 2  --- 12
   3<< 3  --- 24 <= 32
   3<< 4  --- 48  >32
   take shift = 3
   res += 1 << 3 = 8
   divd = 32 - 24 = 8
 8/3 
   3<< 1 --- 6 <=8
   3<< 2 --- 12 > 8
   res += 1 << 1 = 8+2 = 10
   divd = 8 - 6 < 3 --- done
*/
//runtime 0, faster than 100%, mem less than 36%
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN) {
            if (divisor == -1) return INT_MAX;
            else if (divisor == 1) return INT_MIN;
        }

        long divd = (long) dividend;
        long divs = (long) divisor;
        int sign = 1;
        if (divd < 0) {
            divd = -divd;
            sign = -sign;
        }
        if (divs < 0) {
            divs = - divs;
            sign = -sign;
        }
        int res = 0;
        while (divd >= divs) {
            int shift0 = 0, shift1 = 0;
            while (divd >= divs << shift1) {
                shift0 = shift1;
                shift1++;
            }
            //now divd < dis << shift
            res += 1 << shift0;
            divd -= divs << shift0; 
        }
        //now divd < divs, not enough for 1 divs any more
        return res*sign;
    }
};
