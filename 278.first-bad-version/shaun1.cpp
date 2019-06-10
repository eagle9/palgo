// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
//shaun's own idea and code, left + 1 < right => left < right -1, accepted
//jz template, runtime 0ms, faster than 100%, mem less than 9.8%
class Solution1 {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right - 1) {
            int mid = left + (right - left)/2;
            if (isBadVersion(mid)) // push to the left to find the first
                right = mid;
            else {// go right 
                //left = mid + 1; //okay
                left = mid; //okay too
            }
                
        }
        //left right next to each other
        if (isBadVersion(left)) return left;
        else return right;  //problem statement, there must exist a bad version
    }
    
    
};

//grandyang template
//runtime 0, faster than 100%, mem less than 7%
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
            //else left = mid;  //TLE
        }
        return left;
    }
};
