/*
lt discuss, good and clean idea and code
start from the edges, Pacific(i = 0, j = 0); Atlantic(i = x_len-1, j = y_len-1).
used two boolean[][] (used1, used2) to record the points which is equal or bigger than the value of the edges' point.
find out the common points between the two boolean[][] array.

Runtime: 4 ms, faster than 87.17% of Java online submissions for Pacific Atlantic Water Flow.
Memory Usage: 40.3 MB, less than 100.00% of Java online submissions for Pacific Atlantic Water Flow.

*/
class Solution {
    public int[][] directions = {{1,0}, {-1,0},{0,1},{0,-1}};
    public int x_len, y_len;
    public List<List<Integer>> result = new ArrayList<>();
    
    //dfs matrix, using visited matrix, see which xy can be visited following the inbound and = or > rule
    //from ocean back to continent
    //x y will assured to be inbound
    public void dfs(int[][] matrix, int x, int y, boolean[][] visited){
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            int newx = x+directions[i][0];
            int newy = y+directions[i][1];
            //skip outbound
            if(newx < 0 || newy < 0 || newx >= x_len || newy >= y_len){
                continue;
            }
            //from xy to new xy should = or up
            if(matrix[x][y] <= matrix[newx][newy] && !visited[newx][newy]){
                dfs(matrix, newx, newy, visited);
            }
        }
    }
    
    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        x_len = matrix.length;
        if(x_len == 0) return result;
        y_len = matrix[0].length;
        boolean[][] used1 = new boolean[x_len][y_len];
        boolean[][] used2 = new boolean[x_len][y_len];
        for(int i = 0; i < x_len; i++){
            for(int j = 0; j < y_len; j++){
                if(i == 0 || j == 0){ //from all pacific cells, shared used1, reduce repeated marking
                    dfs(matrix, i , j, used1);
                }
                if(i == x_len -1 || j == y_len-1){ //from all atlantic cells, share used2, reduce repeated marking
                    dfs(matrix, i, j, used2);
                }
            }
        }
        //now examine all cells in the matrix
        for(int i = 0; i < x_len; i++){
            for(int j = 0; j < y_len; j++){
                if(used1[i][j] && used2[i][j]){ //can reach from both pacific and atlantic
                    List<Integer> temp = new ArrayList<>();
                    temp.add(i);
                    temp.add(j);
                    result.add(temp);
                }
            }
        }
        return result;
    }
}
