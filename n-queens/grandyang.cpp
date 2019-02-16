/*
Runtime: 12 ms, faster than 87.27% of C++ online submissions for N-Queens.
Memory Usage: 10.1 MB, less than 100.00% of C++ online submissions for N-Queens.
grandyang recursion with backtracking
*/

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> pos(n, -1);
        solveNQueensDFS(pos, 0, res);
        return res;
    }
    void solveNQueensDFS(vector<int> &pos, int row, vector<vector<string> > &res) {
        int n = pos.size();
        if (row == n) {
            vector<string> out(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                out[i][pos[i]] = 'Q';
            }
            res.push_back(out);
        } else {
            for (int col = 0; col < n; ++col) {
                if (isValid(pos, row ,col)) {
                    pos[row] = col;
                    solveNQueensDFS(pos, row + 1, res);
                    pos[row] = -1;
                }
            }
        }
    }
    bool isValid(vector<int> &pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
                return false;
            }
        }
        return true;
    }
};
