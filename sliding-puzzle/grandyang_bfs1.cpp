/*
grandyang bfs 1, 
Runtime: 8 ms, faster than 100.00% of C++ online submissions for Sliding Puzzle.
Memory Usage: 10.4 MB, less than 64.15% of C++ online submissions for Sliding Puzzle.

not fully understand
understdood now
*/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int res = 0, m = board.size(), n = board[0].size();
        string target = "123450", start = "";
        // z  1  2           0  z  2          0 1 z     0 1 2  0 1 2    0 1 2
        // 3                    4                 5     z 4    3 z 5 .  3 4 z
        vector<vector<int>> dirs{{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                start += to_string(board[i][j]);
            }
        }
        unordered_set<string> visited{start};
        queue<string> q; q.push(start);
        while (!q.empty()) {
            int n = q.size();
            for (int i = n-1; i >= 0; --i) {
                string cur = q.front(); q.pop();
                if (cur == target) return res;
                int zero_idx = cur.find("0");
                //dir is the neighboring zero positions
                for (int dir : dirs[zero_idx]) {
                    string cand = cur;
                    swap(cand[dir], cand[zero_idx]);
                    if (visited.count(cand)) continue;
                    visited.insert(cand);
                    q.push(cand);
                }
            }
            ++res; //increase level
        }
        return -1;
    }
};
