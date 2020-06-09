//http://lixinchengdu.github.io/algorithmbook/leetcode/minimum-knight-moves.html
class Solution {
public:
    int minKnightMoves(int x, int y) {
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        q.push({0, 0});

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int n = 0; n < size; ++n) {
                auto pos = q.front(); q.pop();
                if (abs(pos.first) == abs(x) && abs(pos.second) == abs(y))  return level;
                if (visited.count({abs(pos.first), abs(pos.second)})) continue;
                visited.insert({abs(pos.first), abs(pos.second)});
                for (int i = 0; i < 8; ++i) {
                    q.push({pos.first + directions[i][0], pos.second + directions[i][1]});
                }
            }
            ++level;
        }
        return -1;
    }


private:
    int directions[8][2] = {
        {1, 2}, 
        {2, 1},
        {2, -1},
        {1, -2},
        {-1, -2},
        {-2, -1},
        {-2, 1},
        {-1, 2}
    };
};
