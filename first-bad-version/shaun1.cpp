// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

//shaun's own idea and code, left + 1 < right => left < right -1, accepted
//runtime 4ms, faster than 100%, mem less than 32%
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right - 1) { // left +1 < right may overflow
            int mid = left + (right - left)/2;
            if (isBadVersion(mid)) // push to the left to find the first
                right = mid;
            else // go right
                left = mid + 1;
        }
        //left right next to each other
        if (isBadVersion(left)) return left;
        else return right;  //problem statement, there must exist a bad version
    }
};
