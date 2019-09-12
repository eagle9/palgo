//grandyang bfs 
//runtime 92ms, faster than 67%, mem less than 60%
//cutting: bfs from all gates, push all gates into queue
// use room[i][j] to store the distance from any of the gates, since gate cell value is 0, so room[i][j] +1 from gate room[][]

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>> gates;
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[i].size(); ++j) {
                if (rooms[i][j] == 0) gates.push({i, j});   
            }
        }
        while (!gates.empty()) {
            auto gate = gates.front(); gates.pop();
            queue<pair<int, int>> q;
            q.push(gate);
            while (!q.empty()) {
                int i = q.front().first, j = q.front().second; q.pop();
                for (int k = 0; k < dirs.size(); ++k) {
                    int x = i + dirs[k][0], y = j + dirs[k][1];
                    //skip if out bound or room[x][y] already better than room[i][j]+1
                    if (x < 0 || x >= rooms.size() || y < 0 || y >= rooms[0].size() || rooms[x][y] < rooms[i][j] + 1) continue;
                    rooms[x][y] = rooms[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
    }
};
