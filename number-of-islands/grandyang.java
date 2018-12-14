class Solution {
    public int numIslands(char[][] grid) {
        if (grid.length == 0 || grid[0].length ==0)
            return 0;
        int m = grid.length, n = grid[0].length, res = 0;
        boolean [][]visited = new boolean[m][n];
        for (int i =0; i < m ; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfsy(grid, visited,i,j);
                    res++;
                }
            }
        }
        return res;
    }
    private void dfs(char[][] grid, boolean [][] visited, int i, int j) {
        //recursive dfs exit cases
        if (i < 0 || i >= grid.length) return;
        if (j < 0 || j >= grid[0].length) return;
        
        if (visited[i][j] || grid[i][j] != '1')
            return;
        
        //now i and j all in bound
        visited[i][j] = true;
        
        //extending 1's that makes up the island
        
            dfs(grid,visited,i,j+1);
        
            dfs(grid,visited,i,j-1);
        
            dfs(grid,visited,i+1,j);
        
            dfs(grid,visited,i-1,j);
    }
    
    //stackoverflow
    private void dfsy(char[][] grid, boolean [][] visited, int i, int j) {
        //recursive dfs exit cases
        if (i < 0 || i >= grid.length) return;
        if (j < 0 || j >= grid[0].length) return;
        
        
        //now i and j all in bound
        visited[i][j] = true;
        
        //extending 1's that makes up the island
        if (grid[i][j+1] == '1')
            dfsy(grid,visited,i,j+1);
        if (grid[i][j-1] == '1')
            dfsy(grid,visited,i,j-1);
        if (grid[i+1][j] == '1')
            dfsy(grid,visited,i+1,j);
        if (grid[i-1][j] == '1')
            dfsy(grid,visited,i-1,j);
    }

}



//grandyang, beats 99%, natural idea with dfs
/*
这道求岛屿数量的题的本质是求矩阵中连续区域的个数，很容易想到需要用深度优先搜索DFS来解，我们需要建立一个visited数组用来记录某个位置是否被访问过，对于一个为‘1’且未被访问过的位置，我们递归进入其上下左右位置上为‘1’的数，将其visited对应值赋为true，继续进入其所有相连的邻位置，这样可以将这个连通区域所有的数找出来，并将其对应的visited中的值赋true，找完次区域后，我们将结果res自增1，然后我们在继续找下一个为‘1’且未被访问过的位置，以此类推直至遍历完整个原数组即可得到最终结果，代码如下：


class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    numIslandsDFS(grid, visited, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
    void numIslandsDFS(vector<vector<char> > &grid, vector<vector<bool> > &visited, int x, int y) {
        if (x < 0 || x >= grid.size()) return;
        if (y < 0 || y >= grid[0].size()) return;
        if (grid[x][y] != '1' || visited[x][y]) return;
        visited[x][y] = true;
        numIslandsDFS(grid, visited, x - 1, y);
        numIslandsDFS(grid, visited, x + 1, y);
        numIslandsDFS(grid, visited, x, y - 1);
        numIslandsDFS(grid, visited, x, y + 1);
    }
};
*/
