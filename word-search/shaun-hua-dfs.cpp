//hua dfs, similar to gy,
//clever trick to avoid use visisted array, use special board[i][j] value 0
//can be thought of on optimization of gy's dfs
//huahua's dfs with backtracking, 332ms, faster than 32%
//shaun later changed helper(string word) to string& word
//runtime 24ms, faster than 89%, mem less than 88%
class Solution {
    public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        m_ = board.size(), n_ = board[0].size();
        //vector<vector<bool>> visited(m_, vector<bool>(n_, false));
        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                if (helper(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, string& word, int d, int i, int j) {
        if (i < 0 || i == m_ || j < 0 || j == n_ || board[i][j] != word[d]) return false;
        if (d == word.size()-1) return true;
        
        bool res = false;
        
        char save = board[i][j];
        board[i][j] = 0;
        res = helper(board, word, d + 1, i-1, j)
                ||helper(board, word, d + 1, i+1, j)
                ||helper(board, word, d + 1, i, j-1)
                ||helper(board, word, d + 1, i, j+1);
            
        board[i][j] = save; //backtracking, key here, why?  when no way to go true, reset back for other starting point dfs
        
        return res;
    }
private:
    int m_,n_;
    
};


