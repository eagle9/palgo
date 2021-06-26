//jz bfs, beats 48%
public class Solution {
    /*
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */

    private final int[][] MOVES = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    public int minArea(char[][] image, int x, int y) {
        // BFS -> Time: O(S), S == Area of black pixels region; Space: O(S)
        int n = (image == null) ? 0 : image.length;
        int m = (n == 0) ? 0 : image[0].length;
        if (n == 0 || m == 0) {
            return 0;
        }

        int minX = Integer.MAX_VALUE;
        int minY = Integer.MAX_VALUE;
        int maxX = Integer.MIN_VALUE;
        int maxY = Integer.MIN_VALUE;

        Queue<Pair> queue = new LinkedList<>();

        queue.offer(new Pair(x, y));
        image[x][y] = 0;

        while (!queue.isEmpty()) {
            Pair curr = queue.poll();

            minX = Math.min(minX, curr.x);
            minY = Math.min(minY, curr.y);
            maxX = Math.max(maxX, curr.x);
            maxY = Math.max(maxY, curr.y);

            for (int[] move : MOVES) {
                int nx = curr.x + move[0];
                int ny = curr.y + move[1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && image[nx][ny] == '1') {
                    queue.offer(new Pair(nx, ny));
                    image[nx][ny] = 0;
                }
            }
        }

        int width = maxY - minY + 1;
        int height = maxX - minX + 1;

        return width * height;
    }
}

class Pair {
    public int x;
    public int y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
