//Your submission beats 78.20% Submissions!
//jiadai
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int start = 1, end = n;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (SVNRepo::isBadVersion(mid)) {  //front part
                end = mid;
            }
            else { //good, then back part
                start = mid;
            }
        }
       	//start + 1 == end now 
        if (SVNRepo::isBadVersion(start)) {
            return start;
        }
        else {
            return end;
        }
    }
};
