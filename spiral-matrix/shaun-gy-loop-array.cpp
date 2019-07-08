//grandyang array and loop
//runtime 0ms, faster than 100%, mem less than 82%
//cutting, easy to do it manually, what about the manual? 
// loop loop loop loop with changed parameters
// so a loop with 4 loops with updates
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (true) {
            //go from left to right along top row
            for (int j = left; j <= right; ++j) res.push_back(matrix[top][j]);
            if (++top > bottom) break; //update top and see if reach over bottom
            
            //go from top to bottom along right column
            for (int i = top; i <= bottom; ++i) res.push_back(matrix[i][right]);
            if (--right < left) break; //update right
            
            //go from right to left along bottom row
            for (int j = right; j >= left; --j) res.push_back(matrix[bottom][j]);
            if (--bottom < top) break; //update bottom
            
            //go from bottom to top along left column
            for (int i = bottom; i >= top; --i) res.push_back(matrix[i][left]);
            if (++left > right) break; //update left
        }
        return res;
    }
};
