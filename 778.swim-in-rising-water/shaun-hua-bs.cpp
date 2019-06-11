//hua binary search idea, to understand more
//runtime 16ms, faster than 99%, mem less than 41%
class Solution1 {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();
        auto hasPath = [&grid, n](int t) {
            if (grid[0][0] > t) return false;      
            queue<int> q;
            vector<int> seen(n * n);
            vector<int> dirs{1, 0, -1, 0, 1};
            q.push(0);
      
            while (!q.empty()) {
                const int x = q.front() % n;
                const int y = q.front() / n;
                q.pop();
                if (x == n - 1 && y == n - 1) return true;
                for (int i = 0; i < 4; ++i) {
                    const int tx = x + dirs[i];
                    const int ty = y + dirs[i + 1];
                    if (tx < 0 || ty < 0 || tx >= n || ty >= n || grid[ty][tx] > t) continue;
                    const int key = ty * n + tx;
                    if (seen[key]) continue;
                    seen[key] = 1;
                    q.push(key);
                }
            }
            return false;
        };
        int left = 0, right = n * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (hasPath(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();

        int left = 0, right = n * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (hasPath(grid,mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
private:
    bool hasPath(vector<vector<int>>& grid,int t) {
        if (grid[0][0] > t) return false;
        int n = grid.size();
        queue<int> q;
        vector<int> seen(n * n);
        vector<int> dirs{1, 0, -1, 0, 1};
        q.push(0);
      
        while (!q.empty()) {
                const int x = q.front() % n;
                const int y = q.front() / n;
                q.pop();
                if (x == n - 1 && y == n - 1) return true;
                for (int i = 0; i < 4; ++i) {
                    const int tx = x + dirs[i];
                    const int ty = y + dirs[i + 1];
                    if (tx < 0 || ty < 0 || tx >= n || ty >= n || grid[ty][tx] > t) continue;
                    const int key = ty * n + tx;
                    if (seen[key]) continue;
                    seen[key] = 1;
                    q.push(key);
                }
        }
        return false;
    };
};
