/*
grandyang dfs with backtracking
cutting try all starting cell, dfs path along the word string, reach end?
shaun deep read and modified according to shaun's first time idea

Runtime: 320 ms, faster than 36.08% of C++ online submissions for Word Search.
Memory Usage: 164.8 MB, less than 100.00% of C++ online submissions for Word Search.
used vector<pair<int,int>> for dir_, Runtime: 176 ms, faster than 43.40% 
*/
class Solution1 {
    public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        m_ = board.size(), n_ = board[0].size();
        vector<vector<bool>> visited(m_, vector<bool>(n_, false));
        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                if (helper(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, string word, int idx, int i, int j, vector<vector<bool>>& visited) {
        if (idx == word.size()) return true;
        
        bool res = false;
        //in bound, not visited, grid[i][j] == word[idx]
        if (i >= 0 && j >= 0 && i < m_ && j < n_ && !visited[i][j] && board[i][j] == word[idx]) {
            visited[i][j] = true;
            for (auto v: dir_) {
                //int ni = i + v[0], nj = j + v[1];
                int ni = i + v.first, nj = j + v.second;
                if (helper(board, word, idx + 1, ni, nj, visited)) {
                    res = true;
                    break;
                }
            }
            visited[i][j] = false; //backtracking, key here, why????
        }
        return res;
    }
private:
    int m_,n_;
    //up  down  
    //vector<vector<int>> dir_ = {{-1,0}, {1,0},{0,-1},{0,1}};
    vector<pair<int,int>> dir_ = {{-1,0}, {1,0},{0,-1},{0,1}};
    
    
};
//huahua's dfs with backtracking, 332ms, faster than 32%
class Solution {
    public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        m_ = board.size(), n_ = board[0].size();
        vector<vector<bool>> visited(m_, vector<bool>(n_, false));
        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                if (helper(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, string word, int d, int i, int j) {
        if (i < 0 || i == m_ || j < 0 || j == n_ || board[i][j] != word[d]) return false;
        if (d == word.size()-1) return true;
        
        bool res = false;
        
        char save = board[i][j];
        board[i][j] = 0;
        res = helper(board, word, d + 1, i-1, j)
                ||helper(board, word, d + 1, i+1, j)
                ||helper(board, word, d + 1, i, j-1)
                ||helper(board, word, d + 1, i, j+1);
            
        board[i][j] = save; //backtracking, key here, why????
        
        return res;
    }
private:
    int m_,n_;
    
};
