/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */

 //jiadai c++ --> java beats 98.80%
public class Solution {
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    public List<Integer> numIslands2(int n, int m, Point[] operators) {
        List<Integer> result = new ArrayList<>();
        if (operators == null) 
            return result;
        /*
        if (n <= 0 || m <= 0) {
            return result;
        }*/
        
        
        int count = 0;
        int [] parent = new int [n * m]; // -1);
        //Arrays.fill(parent,-1); //works but slower
        for (int i = 0; i < parent.length; i++) {
            parent[i] = -1; //set to -1 is key, default value 0 won't work
        }
        int [] deltaX = {-1, 1, 0, 0};
        int [] deltaY = {0, 0, -1, 1};
        
        for (Point  p : operators) {
            int x = p.x;
            int y = p.y;
            int pos = x * m + y;
            if (parent[pos] == -1) {
                ++count;
                parent[pos] = pos;
                for (int i = 0; i < deltaX.length; ++i) {
                    int nx = x + deltaX[i];
                    int ny = y + deltaY[i];
                    int npos = nx * m + ny;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || parent[npos] == -1) {
                        continue;
                    }
                    
                    int posParent = findParent(parent, pos);
                    int nposParent = findParent(parent, npos);
                    if (posParent != nposParent) {
                        --count;
                        parent[posParent] = nposParent;
                    }
                }
            }
            
            result.add(count);
        }
        
        return result;
    }
    private int findParent(int [] parent, int pos) {
        while (parent[pos] != pos) {
            parent[pos] = parent[parent[pos]];
            pos = parent[pos];
        }
        
        return pos;
    }
};
