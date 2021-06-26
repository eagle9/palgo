//hua dijkstra idea, hua use pair<-time, x + y*N>
//great idea to use int xy = x + y*N to represent coordinate
// if you use pair<int,int>, you have to add hash function, which is not easy to implement

//shaun use struct<time,xy> with operator <, a litle bit more code, but easier to get correct

//runtime 12ms, faster than 99%, mem less than 79%
struct record {
    int time;
    int xy;
    bool operator <(record other) const {
        return time > other.time;
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();
        priority_queue<record> q; // {time, y * N + x}
        q.push(record{grid[0][0], 0 * n + 0});
        vector<int> seen(n * n);
        vector<int> dirs{-1, 0, 1, 0, -1};
        seen[0 * n + 0] = 1;
        while (!q.empty()) {
            auto node = q.top(); q.pop();
            int t = node.time;
            int x = node.xy % n;
            int y = node.xy / n;      
            if (x == n - 1 && y == n - 1) return t;
            for (int i = 0; i < 4; ++i) {
                int tx = x + dirs[i];
                int ty = y + dirs[i + 1];
                if (tx < 0 || ty < 0 || tx >= n || ty >= n) continue;
                if (seen[ty * n + tx]) continue;
                seen[ty * n + tx] = 1;
                q.push({max(t, grid[ty][tx]), ty * n + tx});
            }
        }   
        return -1;
    }
};
