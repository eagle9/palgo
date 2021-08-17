/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int left = 1, right = n;
        //exit when left == right-1, left + 1 might overflow int
        while (left  < right -1) {
            int mid = left + (right-left)/2;
            if (isBadVersion(mid)) // push to the left to find the first
                right = mid;
            else // go right
                //left = mid + 1;
                left = mid;
        }
        //left right next to each other
        if (isBadVersion(left)) return left;
        else return right;  //problem statement, there must exist a bad version
    }
    
    //with left = mid+1, we can use left < right loop exit condition
    public int firstBadVersion2(int n) {
        int left = 1, right = n;
        //exit when left == right-1, left + 1 might overflow int
        while (left  < right) {
            //int mid = left + (right-left)/2;
            int mid = left + ((right-left)>>1);
            if (isBadVersion(mid)) // push to the left to find the first
                right = mid;
            else // go right
                left = mid + 1;
        }
        //left == right now
        if (isBadVersion(left)) return left;
        else return left+1;  //problem statement, there must exist a bad version
    }
    
}

