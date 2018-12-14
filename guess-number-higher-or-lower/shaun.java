/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    /**
     * @param n an integer
     * @return the number you guess
     */
     //shaun TLE first try
     //modified some details, beats 100%
    public int guessNumber(int n) {
        // Write your code here
        
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
        return left;
        //return -1;
    }
    
    
    //jz beats 62.60
    public int guessNumberJz(int n) {
        // Write your code here
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int res = guess(mid);
            if (res == 0) {
                return mid;
            }
            
            if (res == -1) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
}
