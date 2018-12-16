//jidaai, beats 17%, lintcode output in order of closeness
//while leetcode in its original order
class Solution {
public:
    /*
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
     //Your submission beats 91.60% Submissions at lintcode
    // after slight modification, accepted at leetcode, beats 66%
     //jiadai
     //not yet understand 
    vector<int> findClosestElements(vector<int> &A, int k, int target) {
        // write your code here
        int n = A.size();
        if (n == 0) {
            return {};
        }
        
        int start = 0, end = n - 1;
        //key is start + 1 < end, otherwise start+1=end, mid will always be start, loop never exits
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            //start -- mid covers target
            if (A[mid] >= target) {
                end = mid;
            }
            else { // A[mid] < target ==> mid--end covers target
                start = mid + 1; //okay
                //start = mid;  //okay
            }
        }
        //now start+1 == end
        // target   A[start]   A[end]   target
        //now try to find the first elment index >= target
        int index;
        if (target <= A[start]) {
            index = start;
        }
        else if (A[end] >= target) {      ///A[start] target A[end]
            index = end;
        }
        else { // A[start]A[end] target
            index = end + 1;
        }
        
        int left = index - 1, right = index;
        vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            if (right >= n) { //right outbound, take left
                result[i] = A[left--];
            } 
            else if (left < 0) { //left outbound, take right
                result[i] = A[right++];
            }
            //check which side is closer
            else if (target - A[left] <= A[right] - target) {
                result[i] = A[left--];
            }
            else {
                result[i] = A[right++];
            }
        }
        //sort is for leetcode only
        sort(result.begin(), result.end());
        return result;
    }
};
