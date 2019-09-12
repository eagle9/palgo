/*
grandyang bfs 1, shaun understands and modified

runtime 4ms, faster than 98%, mem less than 83%

cutting: model with graph bfs, reach from a given node to a target node
1 board state --> 1 node in the graph
represent a node with a string
figure out 0's next move for each possible board index of 0, all neighbors
*/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        string target = "123450", start = "";
        // z  1  2           0  z  2          0 1 z     0 1 2  0 1 2    0 1 2
        // 3                    4                 5     z 4    3 z 5 .  3 4 z
        vector<vector<int>> dirs{{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                start += to_string(board[i][j]);
            }
        }
        //unordered_set<string> visited{start};
        unordered_set<string> visited; visited.insert(start);
        queue<string> q; q.push(start);
        //bfs level by level
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = n-1; i >= 0; --i) {
                string cur = q.front(); q.pop();
                if (cur == target) return level;
                int zero_idx = cur.find("0");
                //next_idx is the legal neighboring zero positions
                for (int next_idx : dirs[zero_idx]) {
                    string cand = cur;//make a copy
                    swap(cand[next_idx], cand[zero_idx]);
                    if (visited.count(cand)) continue;
                    visited.insert(cand);
                    q.push(cand);
                }
            }
            ++level; //increase level
        }
        //q empty now, and target not reached, return -1
        return -1;
    }
};
