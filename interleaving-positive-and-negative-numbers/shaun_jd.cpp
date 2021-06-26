//jiadai code, shaun read and understand, beats 68%
class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        if (A.empty()) return;
        int n = A.size();
        int posNum = 0, negNum = 0;
        for (int num : A){
            if (num >= 0) ++posNum;
            else ++negNum;
        }
        
        int ipos = (posNum >= negNum) ? 0 : 1;
        int ineg = 1 - ipos;
        while (ipos < n && ineg < n) {
            while (ipos < n && A[ipos] > 0) ipos += 2;
            while (ineg < n && A[ineg] < 0) ineg += 2;
            
            if (ipos < n && ineg < n){
                swap(A[ipos], A[ineg]);
                ipos += 2;
                ineg += 2;
            }
        }
    }
};
