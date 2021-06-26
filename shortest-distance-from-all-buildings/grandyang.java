//grandyang idea2, shaun java code, beats 35%
//key point: level, dist are yet fully understood
/*
用BFS来做，其中dist是累加距离场，cnt表示某个位置已经计算过的建筑数，变量buildingCnt为建筑的总数，我们还是用queue来辅助计算，注意这里的dist的更新方式跟上面那种方法的不同，这里的dist由于是累积距离场，所以不能用dist其他位置的值来更新，而是需要直接加上和建筑物之间的距离，这里用level来表示，每遍历一层，level自增1，这样我们就需要所加个for循环，来控制每一层中的level值是相等的，
understand a little now with the description
*/
class Solution {
    class Pair {
        int i;
        int j;
        public Pair(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }
    public int shortestDistance(int[][] grid) {
        int res = Integer.MAX_VALUE, buildingCnt = 0;
        int m = grid.length, n = grid[0].length;
        int [] [] dist = new int[m][n]; //distance from a building
        int [] [] cnt = new int[m][n]; //what is this? 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cnt[i][j] = grid[i][j];
            }
        }
        int [] [] dir = {{0,-1},{-1,0},{0,1},{1,0}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    buildingCnt++;
                    Queue<Pair> q = new LinkedList<>();
                    q.offer(new Pair(i,j));
                    boolean [] [] visited = new boolean[m][n];
                    int level = 1;  //why this variable????
                    while (!q.isEmpty()) {
                        int size = q.size();
                        for (int s = 0; s < size; s++) {
                            Pair p = q.poll();
                            int a = p.i, b = p.j;
                            //for all 4 direction moves, left right up and down
                            for (int k = 0; k <= 3; k++) {
                                int x = a + dir[k][0];
                                int y = b + dir[k][1];
                                //in bound, not visited, empty land
                                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0 && !visited[x][y]) {
                                    dist[x][y] += level;
                                    cnt[x][y]++;
                                    visited[x][y] = true;
                                    q.offer(new Pair(x,y));
                                }
                            }
                            
                        }
                        //now done with all grid cells at this level
                        level++;
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && cnt[i][j] == buildingCnt) {
                    res = Math.min(res, dist[i][j]);
                }
            }
        }
        return res == Integer.MAX_VALUE ? -1 : res;
        
    }
}


