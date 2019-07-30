//grandyang idea with hashtable, cutting: how to check if a number 1-9 only occurs once in a row ( a colum or 3x3 cell)?   hash, or simply array
//how to come up cell index?  0-2 345 678 ---> i/3  j/3, combine a*3 + b
//runtime 16ms, faster than 68%, mem less than 34%
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > rowFlag(m, vector<bool>(n, false));
        vector<vector<bool> > colFlag(m, vector<bool>(n, false));
        vector<vector<bool> > cellFlag(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int c = board[i][j] - '1'; //why -'1', 012 345 678, easier to calculate cell index
                    if (rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + j / 3][c]) return false;
                    rowFlag[i][c] = true;
                    colFlag[c][j] = true;
                    cellFlag[3 * (i / 3) + j / 3][c] = true;
                }
            }
        }
        return true;
    }
};

