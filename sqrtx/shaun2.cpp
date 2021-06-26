//shaun's original idea, mid*mid > x overflow issue, after avoiding this issue, accepted, runtime 8ms, faster than 94%, mem less than 99%
class Solution1 {
public:
    //x >= 0
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int left  = 1, right = x;
        while (left +1 < right) {
            int mid = left + (right - left)/2;
            if (mid  > x/mid)   //push to left
                right = mid;
            else // mid * mid <= x
                left = mid;
        }
        //left right
        if (right <= x/right) return right;
        else return left;
    }
};

//grandyang & hua template, check hua binary search SP
//0ms, faster than 100%, mem less than 64%
class Solution {
public:
    //x >= 0
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int left  = 1, right = x;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (mid  > x/mid)   //push to left
                right = mid;
            else // mid * mid <= x
                left = mid+1;
        }
        //right is the first >, so return right-1, which is last <= 
        //left(mid) right: left = mid+1 == right
        return right-1; // right * right >x 
    }
};

