/*
grandyang dfs with backtracking
shaun deep read and modified according to shaun's first time idea

i like gy's dfs better than hua's, more in line with my idea

used vector<pair<int,int>> for dir_, Runtime: 176 ms, faster than 43.40%, mem less than 42%

helper(string word) ---> string& word
speed up a lot, runtime 32ms, faster than 73%, mem less than 68%
*/
class Solution {
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
    bool helper(vector<vector<char>>& board, string& word, int idx, int i, int j, vector<vector<bool>>& visited) {
        if (idx == word.size()) return true;
        
        bool res = false;
        //in bound, not visited, grid[i][j] == word[idx]
        if (i >= 0 && j >= 0 && i < m_ && j < n_ && !visited[i][j] && board[i][j] == word[idx]) {
            visited[i][j] = true;
            for (auto v: dir_) {
                //int ni = i + v[0], nj = j + v[1];
                int ni = i + v.first, nj = j + v.second;
                if (helper(board, word, idx + 1, ni, nj, visited)) {
                    //res = true;
                    return true;
                    //break;
                }
            }
            //if not reach, reset back, since each dfs use this visited array
            visited[i][j] = false; //backtracking, key here, why????
        }
        return false;
        //return res;
    }
private:
    int m_,n_;
    //up  down  
    //vector<vector<int>> dir_ = {{-1,0}, {1,0},{0,-1},{0,1}};
    vector<pair<int,int>> dir_ = {{-1,0}, {1,0},{0,-1},{0,1}};
    
    
};
