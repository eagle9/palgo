//cutting:  Two binary search
//first binary search the first column to determine right now, last i < target
// then binary search the row from left to right to find the target
//grandyang, runtime 12ms, faster than 99%
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        
        //find row first, binary search first column, 
        //last index < 
        int left = 0, right = matrix.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) left = mid + 1; //when < target , push to right, so last idx < target
            else right = mid;
        }
        //left == right now
        int row = right;
        if (matrix[right][0] > target) row = right-1;
        
        left = 0;
        right = matrix[row].size() - 1;
        /*
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;*/
        while (left < right) {
            int mid = left + (right- left) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) left = mid + 1;
            else right = mid;
        }
        //left == right
        if (matrix[row][right] == target) return true;
        else return false;
    }
};

