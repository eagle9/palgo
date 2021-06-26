//lt2 binary search, n logn time
//naive binary search each row and column
//runtime 244ms, faster than 13%, mem less than 63%
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        m = matrix.size();
        n = matrix[0].size();
        /*
        //faster than 15%
        for (int i = 0; i < m; ++i) {
            if (binary_search_row(matrix, i, target)) return true;
        }
        for (int j = 0; j < n; ++j) {
            if (binary_search_col(matrix, j, target)) return true;
        }*/
        for (int i = 0; i < min(m,n); ++i) {
            if (binary_search_row(matrix, i, target)) return true;
            if (binary_search_col(matrix, i, target)) return true;
        }
        return false;
    }
private:
    int m,n;
    bool binary_search_row(vector<vector<int>>& matrix, int i, int target) {
        //binary search row i from 0 to n-1
        int left = 0;
        int right = n-1;

        while (left <= right) {
            int mid = left + (right-left)/2;
            if (matrix[i][mid] < target) {
                    left = mid + 1;
            } else if (matrix[i][mid] > target) {
                    right = mid - 1;
            } else { // == target
                    return true;
            }
        }
        return false;
    }
    bool binary_search_col(vector<vector<int>>& matrix, int j, int target) {        
        int left = 0, right = m-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (matrix[mid][j] < target) {
                left = mid + 1;
            } else if (matrix[mid][j] > target) {
                right = mid - 1;
            } else { // == target
                return true;
            }
            
        }

        return false;
    }
};

