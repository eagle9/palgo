//grandyang bfs, wrong answer, due to typo for (int k =0; k < 3; k++)  should be k<=3
//beats 30% compare to jz solution that uses two queues rather than a queue<Pair>
class Solution {
    class Pair {
        int i;
        int j;
        public Pair(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }
    public void wallsAndGates(int[][] rooms) {
        //keypoint, otherwise array out of bound exception
        if (rooms == null || rooms.length == 0) return;
        
        int [] [] dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int m = rooms.length, n = rooms[0].length;
        Queue<Pair> q = new LinkedList<>();
        for (int i =0; i < m; i++) {
            for (int j=0; j < n; j++) {
                //push all gates into queue, starting nodes
                if (rooms[i][j] == 0) q.offer(new Pair(i,j));
            }
        }
        
        while (!q.isEmpty()) {
            Pair p = q.poll();
            int i = p.i, j = p.j;
            
            //for (int k = 0; k < 3; k++) { //wrong answer due to typo
            for (int k = 0; k <= 3; k++) {
                int ni = i + dir[k][0], nj = j + dir[k][1];
                //dont go outbound
                if (ni < 0 || ni > m-1 || nj < 0 || nj > n-1) continue;
                
                //dont go: better already or walls
                if (rooms[ni][nj]  < rooms[i][j] + 1) continue; //including the walls, positive but <, no need to go there since it is already better
                
                //now rooms[ni][nj] >= rooms[i][j] + 1, current visit is good
                rooms[ni][nj] = rooms[i][j]+1;
                q.offer(new Pair(ni,nj));
            }
        }
        
    }
}

