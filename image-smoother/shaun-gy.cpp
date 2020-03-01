//with gy's idea, runtime 384ms, faster than 6%, mem less than 50%
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return {};
        int m = M.size(), n = M[0].size();
        vector<vector<int>> res(m,vector<int>(n));
        
        /*
        array faster
        int deltas [8][2] = {{-1,0}, {1,0},  //up and down
                     {0,-1},{0,1}, //left and right
                     {1,-1},{-1,1},  //diagonal /
                     {-1,-1},{1,1}}; //diagonal \
                     */
        
        vector<vector<int>> deltas = {{-1,0}, {1,0},  //up and down
                     {0,-1},{0,1}, //left and right
                     {1,-1},{-1,1},  //diagonal /
                     {-1,-1},{1,1}}; //diagonal \
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = 1, sum = M[i][j]; //include itself
                for (auto d: deltas) {
                    int x = i + d[0], y = j + d[1];
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    sum += M[x][y];
                    count++;
            
                }
                res[i][j] = sum/count;
            }
            
        }
        return res;
        
    }
};
