//shaun has read and understand commented grandyang direct idea
//runtime 8ms, faster than 99.56%, mem less than 36%
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int rowsA = A.size(), colsA = A[0].size(), colsB = B[0].size();
        vector<vector<int>> res(rowsA, vector<int>(colsB));
        
        //think C[i][j] = Sigma  A[i][k]*B[k][j]  colsA == rowsB assumed for valid multiplication
        //i from 0 to rowsA
        for (int i = 0; i < rowsA; ++i) {
            //k from 0 to colsA
            for (int k = 0; k < colsA; ++k) {
                if (A[i][k] != 0) {
                    //j from 0 to colsB
                    for (int j = 0; j < colsB; ++j) {
                        if (B[k][j] != 0) res[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        return res;
    }
};
