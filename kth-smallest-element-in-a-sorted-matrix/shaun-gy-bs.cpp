//shaun code from grandyang binary search idea
//runtime 40ms, faster than 91%
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size();
        n = matrix[0].size();
        int left = matrix[0][0], right = matrix[m-1][n-1];
        while (left < right) {
            int mid = left + (right - left)/2;
            if (find(matrix,mid) < k) left = mid+1;
            else right = mid;
        }
        //left == right
        if (find(matrix,left) >= k)
            return left;
        else
            return INT_MIN;
    }
    
private:
    int m,n;
    //find the number of elements <= target
    //start from row m-1, col = 0
    //time = O(m+n)
    int find(vector<vector<int>>& matrix, int target) {
        int i = m-1, j = 0;
        int cnt = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= target) {
                cnt += i+1; //from row 0 to row i, number above ij and itslef
                j++;  //move to right to find more
            }else {  //> target
                i--;  //move up one row
            }
        }
        return cnt;
    }
};
