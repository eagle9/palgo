//shaun first try, first sub 30% test cases passed, wrong answer
class Solution {
public:
    /*
     * @param A: An integer array.
     * @return: nothing
     */
    void rerange(vector<int> &A) {
        int i  = 0, j = 0;
        while (j < A.size() && i < A.size()) {
            //Aj < 0 and not yet where it should be
            if (A[j] < 0 && j%2 == 1) {
                swap(A[i], A[j]);
                i+=2;
                if (A[j] > 0) j++;
                continue;
            }
            
            //Aj >=0 or already where it should be
            j++;
        }
        
    }
};
