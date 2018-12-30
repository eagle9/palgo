
class Solution {
    //grandyang idea2, shaun java code, beats 18%
    public boolean isToeplitzMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        //key point i from 0 to n-2
        for (int i = 0; i < m -1; i++) {
            //row i from 0 to n-2
            //row i+1 from 1 to n-1
            for (int j = 0; j < n - 1; j++) {
                if (matrix[i][j] != matrix[i+1][j+1]) return false;
            }
        }
        return true;
    }
}

/*
grandyang c++
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() - 1; ++i) {
            for (int j = 0; j < matrix[i].size() - 1; ++j) {
                if (matrix[i][j] != matrix[i + 1][j + 1]) return false;
            }
        }
        return true;
    }
    
*/
