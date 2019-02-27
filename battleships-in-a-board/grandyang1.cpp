/*grandyang idea1
Runtime: 8 ms, faster than 100.00% of C++ online submissions for Battleships in a Board.
Memory Usage: 9.6 MB, less than 95.59% of C++ online submissions for Battleships in a Board.


*/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        int res = 0, m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //if (board[i][j] == '.' || (i > 0 && board[i - 1][j] == 'X') || (j > 0 && board[i][j - 1] == 'X')) continue;
                if (board[i][j] == 'X' && (i <= 0 || board[i - 1][j] != 'X') && (j <= 0 || board[i][j - 1] != 'X'))
                    ++res;
            }
        }
        return res;
    }
};
