/*

May 17 2020
idea forming:

i =1 to N*N
each step at row, col and seq no x
for x, get next row col pairs
can reach:  b[row][col] == -1? reach square x+i
            !=-1,  reach square b[][]
            
            
think of square as the node
each squre can reach a bunch of other squares,  total N*N squares
now find the shortest distance from square 1 to N*N
bfs natural solution 


how about dijkstra algo? 
does not improve much

Runtime: 9 ms, faster than 42.99% of Java online submissions for Snakes and Ladders.
Memory Usage: 39.8 MB, less than 83.33% of Java online submissions for Snakes and Ladders.

*/
class Solution {
    public int snakesAndLadders(int[][] board) {
        int N = board.length;

        int [] dist = new int[N*N+1];
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[1] = 0;
        
        //Queue<Integer> queue = new LinkedList();
        PriorityQueue<int[]> queue = new PriorityQueue<>((a,b)->a[0]-b[0]);
        
        queue.offer(new int [] {0,1});

        while (!queue.isEmpty()) {
            int[] pair = queue.poll();
            int s = pair[1];
            if (s == N*N) return dist[s];
            
            //for each neighbor s2Final
            for (int s2 = s+1; s2 <= Math.min(s+6, N*N); ++s2) {
                int rc = get(s2, N);
                int r = rc / N, c = rc % N;
                int s2Final = board[r][c] == -1 ? s2 : board[r][c];
                //s2Final not yet visited
                if (dist[s]+1 < dist[s2Final]) {
                    dist[s2Final] = dist[s]+1;
                    queue.offer(new int[]{dist[s]+1,s2Final});
                }
            }
        }
        
        //can not reach NN
        return -1;
    }

    // Given a square num s, return board coordinates (r, c) as r*N + c
    public int get(int s, int N) {
        int quot = (s-1) / N;
        int rem = (s-1) % N;
        int row = N - 1 - quot;
        int col = row % 2 != N % 2 ? rem : N - 1 - rem;
        return row * N + col;
    }
}

class Solution1 {
    public int snakesAndLadders(int[][] board) {
        int N = board.length;

        Map<Integer, Integer> dist = new HashMap();
        dist.put(1, 0);

        Queue<Integer> queue = new LinkedList();
        queue.offer(1);

        while (!queue.isEmpty()) {
            int s = queue.poll();
            if (s == N*N) return dist.get(s);
            
            //for each neighbor s2Final
            for (int s2 = s+1; s2 <= Math.min(s+6, N*N); ++s2) {
                int rc = get(s2, N);
                int r = rc / N, c = rc % N;
                int s2Final = board[r][c] == -1 ? s2 : board[r][c];
                //s2Final not yet visited
                if (!dist.containsKey(s2Final)) {
                    dist.put(s2Final, dist.get(s) + 1);
                    queue.add(s2Final);
                }
            }
        }
        
        //can not reach NN
        return -1;
    }

    // Given a square num s, return board coordinates (r, c) as r*N + c
    public int get(int s, int N) {
        int quot = (s-1) / N;
        int rem = (s-1) % N;
        int row = N - 1 - quot;
        int col = row % 2 != N % 2 ? rem : N - 1 - rem;
        return row * N + col;
    }
}
