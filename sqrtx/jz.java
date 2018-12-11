//jz idea, beats 60.18%
class Solution {
    public int mySqrt(int x) {
        long left = 1, right = (long)x;
        
        while (left +1 < right){
            long mid = left + (right-left)/2;
            long sq = mid * mid;
            if (sq == (long)x)
                return (int)mid;
            if (sq < (long)x) {
                left = mid;
            }else {
                right = mid;
            }
        }
        
        if (right * right == (long)x)
            return (int)right;
        return (int)left;
    }
}
