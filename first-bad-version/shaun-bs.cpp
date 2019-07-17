// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

//shaun's own idea and code, left + 1 < right => left < right -1, accepted
//runtime 4ms, faster than 100%, mem less than 32%
//jz binary search template, left + 1 < right, exit left+1=right
class Solution1 {
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
//gy hua shaun template, while left < right,  left = mid+1(not mid)
//exit left== right
//runtime 0ms, faster than 100%, mem less than 85%
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) { // left +1 < right may overflow
            int mid = left + (right - left)/2;
            if (isBadVersion(mid)) // push to the left to find the first
                right = mid;
            else // go right
                left = mid + 1;
        }
        //exit prev: left(mid) right --->( left = mid+1, now left==right)
        //exit: left == right
        return right;
    }
};
