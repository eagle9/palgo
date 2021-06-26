//grandyang idea2, shaun has read, understood and commented
//runtime 12ms, faster 99.55%, mem less than 62%
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int rowsA = A.size(), colsB = B[0].size();
        
        vector<vector<int>> res(rowsA, vector<int>(colsB));
        
        //v stores row A non zero element's col index and value pair
        vector<vector<pair<int, int>>> v(rowsA, vector<pair<int,int>>());
        for (int i = 0; i < A.size(); ++i) {
            for (int k = 0; k < A[i].size(); ++k) {
                if (A[i][k] != 0) v[i].push_back({k, A[i][k]});
            }
        }
        //row from 0 to rowsA-1
        for (int i = 0; i < rowsA; ++i) {
            //for each non zero col, cut down k from colsA to very small non zero v
            for (int k = 0; k < v[i].size(); ++k) {
                int col = v[i][k].first;
                int val = v[i][k].second;
                for (int j = 0; j < colsB; ++j) {
                    res[i][j] += val * B[col][j];
                }
            }
        }
        return res;
    }
};
