//grandyang, Runtime: 96 ms, faster than 36.97% of C++ online submissions for Search a 2D Matrix II.
//grandyang idea is same as lt4 search sapce reduction 
//start from bottom left of the matrix
//runtime 80ms, faster than 47%, mem less than 50%
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        
        //start from bottom left 
        //O(m+n) time
        int x = matrix.size() - 1, y = 0;
        while (x >= 0 && y < matrix[0].size()) {
        //while(true) {
            if (matrix[x][y] > target) --x;
            else if (matrix[x][y] < target) ++y;
            else return true;
            //if (x < 0 || y >= matrix[0].size()) break;
        }
        return false;
    }
};
