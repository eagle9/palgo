/*shaun's own idea and code, accepted after 1 fix
cutting, start from each ij, use dfs to mark all connected island elements visited. then boils down to counting new island elements

runtime 12ms, faster than 96%, mem less than 69%
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        m = grid.size();
        n = grid[0].size();
    	//vector<vector<bool>> visited(m, vector<bool>(n));
    	
    	int res = 0;
    	for (int i = 0; i < m; i ++) {
    		for (int j = 0; j < n; j++) {
                //bug 1 --- once add grid[i][j] == '1', immedidately accepted
				//found a new island element, new --> not visited yet, island --> =='1'
    			if (grid[i][j] == '1') { //island cell and not yet visited
    				helper(i,j,grid);
    				res++;
    			}
    		}
    	}
    	return res;
    }
private:
    int m,n;
        //visit i&j cell, dfs, then neighbors, mark all connected island elements visited

    void helper(int i, int j, vector<vector<char>>& grid) {
    	if (i < 0 || i >= m || j < 0 || j >=n ) return; //out bound
    	//if (visited[i][j]) return; //visited already
    	//conected island elements, ==1 and connected
    	if (grid[i][j] == '1') {
    		//visited[i][j] = true;
            grid[i][j] = '0';
    		helper(i+1,j, grid);
    		helper(i-1,j, grid);
    		helper(i,j+1, grid);
    		helper(i,j-1, grid);
    	}
    }
};

