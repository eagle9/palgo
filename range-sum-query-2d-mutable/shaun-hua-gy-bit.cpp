// Binary Indexed Tree 2d, shaun modified gy's 2d bit to hua's 1d style
//prefix sum index always +1 of underlying array or matrix
//runtime 16ms, faster than 89%, mem less than 45%
// cutting 2d bit, bit index +1 of underlying array, +-lowbit function i&-i
//time O(log(m*n)), space O(m*n)
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        mat.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0)); //try mat = matrix, does not work, mat has to be allocated
        bit.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    //update matrix row&col with val
    //matrix cell row&col updated with val, prefix sum impacted only after row+1&col+1, so the loop going up and < bit.size 
    void update(int row, int col, int val) {
        int diff = val - mat[row][col];
        //i j for bit, plus 1
        for (int i = row + 1; i < bit.size(); i += i&-i) {
            for (int j = col + 1; j < bit[i].size(); j += j&-j) {
                bit[i][j] += diff;
            }
        }
        mat[row][col] = val;
    }

    /*   1  B
         A  2
                      
                   r1,c1     
                            row2,col2
        */
    int sumRegion(int row1, int col1, int row2, int col2) {
        //bit index +1
        
        return getSum(row2 + 1, col2 + 1)  //rectangle 1B/A2
            - getSum(row1, col2 + 1)  //rectangle 1B
            - getSum(row2 + 1, col1) //rectangle 1/A
            + getSum(row1, col1);   //rectangle 1
    }
    
    //row and col are bit index, query prefix sum, go to root > 0 and accumulate
    int getSum(int row, int col) {
        int res = 0;
        for (int i = row; i > 0; i -= i&-i) {
            for (int j = col; j > 0; j -= j&-j) {
                res += bit[i][j];
            }
        }
        return res;
    } 
    
private:
    vector<vector<int>> mat;
    vector<vector<int>> bit;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
