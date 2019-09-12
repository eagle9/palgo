//runtime 100ms, faster than 42%, mem less than 71%
//cnt[i][j]  number of buildings that can reach empty land ij
//dist[i][j]  distance to empty land ij,  from all buildings accumulated
//shaun did have bfs idea, 
//cutting: bfs from each building, to all empty lands, for empty land ij, 
//  accumulate bfs level by level distance from each building, reachable building count
//  the pick empty land with the full reachable building count and the minimum accumulated distance 
class Solution {
public:
    //shortest distance from all buildings
    int shortestDistance(vector<vector<int>>& grid) {
        int buildingCnt = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0)), cnt = dist;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) { //1 marks a building
                    ++buildingCnt;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    //bfs level by level from building ij
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    int level = 1;
                    while (!q.empty()) {
                        int size = q.size(); //by level
                        for (int s = 0; s < size; ++s) {
                            int a = q.front().first, b = q.front().second; q.pop();
                            for (int k = 0; k < dirs.size(); ++k) {
                                int x = a + dirs[k][0], y = b + dirs[k][1];
                                //neighbor in bound and empty
                                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0 && !visited[x][y]) {
                                    dist[x][y] += level; //dist from building ij to xy
                                    ++cnt[x][y]; //count of buildings that reach xy
                                    visited[x][y] = true;
                                    q.push({x, y});
                                }
                            }
                        }
                        //done with current level
                        ++level;
                    }
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //check each empty land and the number of buildings reachable is full
                if (grid[i][j] == 0 && cnt[i][j] == buildingCnt) {
                    res = min(res, dist[i][j]);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
