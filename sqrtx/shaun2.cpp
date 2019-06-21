//shaun own idea with binary search of candidate space
//runtime 0ms, faster than 100%, mem less than 73%
class Solution {
public:
    //x is non-negative integer
    //find the first i such that i*i >= x
    //   if i*i = x return i
    //   else return i-1
          
    int mySqrt(int x) {
        int left = 1, right = x;
        while (left < right) {
            int mid = left + (right - left)/2;
            
            //if (mid * mid >= x) {
            if (mid >= x/mid) {
                right = mid;
            }else {
                left = mid+1;
            }
        }
        if (left == x/left) return left;
        else return left - 1;
    }
};
