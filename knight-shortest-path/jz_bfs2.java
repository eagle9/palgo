//jz bfs v2, beats 97.00%
public class Solution {
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path
     */
    public int shortestPath(boolean[][] grid, Point source, Point destination) {
        // write your code here
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return -1;
        }

        int[] dx = {1, 1, -1, -1, 2, 2, -2, -2};
        int[] dy = {2, -2, 2, -2, 1, -1, 1, -1};

        Queue<Point> q = new LinkedList<>();
        boolean[][] v = new boolean[grid.length][grid[0].length];  //Set<Point> v will TLE

        q.offer(source);
        v[source.x][source.y] = true;

        if (source.x == destination.x && source.y == destination.y) {
            return 0;
        }

        int dist = 0;

        while (!q.isEmpty()) {
            dist++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Point cur = q.poll();
                for (int k = 0; k < 8; k++) {
                    int nx = cur.x + dx[k];
                    int ny = cur.y + dy[k];
                    if (0 <= nx && nx < grid.length && 0 <= ny && ny < grid[0].length && !grid[nx][ny] && !v[nx][ny]) {
                        if (nx == destination.x && ny == destination.y) {
                            return dist;
                        }
                        q.offer(new Point(nx, ny));
                        v[nx][ny] = true;
                    }
                }
            }

        }
        return -1;
    }
}
