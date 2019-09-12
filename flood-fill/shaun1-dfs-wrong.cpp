/*


[[1,1,1],
 [1,1,0],
 [1,0,1]]
1
1
2


[[0,0,0],
[0,0,0]]
0
0
2

shaun first try runtime error, wrong answer
*/

class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> res = image;
        if (image.empty()) return res;
        
        //unordered_set<pair<int,int>> visited; //does not compile
        unordered_set<int> visited;
        int color = image[sr][sc];
        helper(res, sr, sc, color, newColor);
        return res;
    }
    void helper(vector<vector<int>>& image, int sr, int sc, int color, int newColor) {
        image[sr][sc] = newColor;
        int id = sr * image.size() + sc;
        //visited.insert(id);
        for (auto d: dirs) {
            int x = sr + d[0], y = sc + d[1];
            //in bound and not yet visited, then dfs, otherwise no dfs
            if (x >= 0 && x < image.size() && y >=0 && y < image[0].size() && image[x][y] == color) {
                helper(image, x, y, color,newColor);
            }
        }
    }
};
