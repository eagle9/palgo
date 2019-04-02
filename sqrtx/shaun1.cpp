//shaun's original idea, mid*mid > x overflow issue, after avoiding this issue, accepted, runtime 8ms, faster than 94%, mem less than 99%
class Solution {
public:
    //x >= 0
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int left  = 1, right = x;
        while (left +1 < right) {
            int mid = left + (right - left)/2;
            if (mid  > x/mid)   //push to left , key: mid*mid > x won't work
                right = mid;
            else // mid * mid <= x
                left = mid;
        }
        //left right
        if (right <= x/right) return right;
        else return left;
    }
};
