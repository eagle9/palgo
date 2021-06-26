// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

//12ms, faster than 100%, mem less than 81%
class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right-left)/2; //good too
            
            //int mid = left + (right-left)>>1; //wont accept
            //int mid = left + ((right-left)>>1);  //good
            int r = guess(mid);
            if (r == 0)
                return mid;
            if (r == -1) //target < mid
                right = mid-1;
                //right = mid; //TLE
            if (r == 1) //target > mid
                left = mid+1;
                //left = mid; //TLE
        }
        //now left == right
        if (guess(left) == 0) return left;
        return -1;
    }
};
