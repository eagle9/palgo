//beats 95.00%
public class Solution {
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    
    class axis{
        int x;
        int y;
        axis(int x, int y){
            this.x=x;
            this.y=y;
        }
    }
         
    public int numIslands(boolean[][] grid) {
        ArrayList<axis> island = new ArrayList<>();
        int nums=0;
        for(int i=0; i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]==true){
                    mark(grid,new axis(i,j));
                    nums++;
                }
            }
        }

       return nums; 
        
    }
  public void mark(boolean[][] grid, axis x){
      Queue<axis> q =new LinkedList<>();
      q.offer(x);
      while(!q.isEmpty()){
          axis tmp= q.poll();
          axis left=new axis(tmp.x-1,tmp.y);
          axis right=new axis(tmp.x+1,tmp.y);
          axis top=new axis(tmp.x,tmp.y-1);
          axis down=new axis(tmp.x,tmp.y+1);
          if(left.x>=0){
              if(grid[left.x][left.y]){
                  q.offer(left);
                 grid[left.x][left.y]=false; 
              }
          }
           if(right.x<grid.length){
              if(grid[right.x][right.y]){
                  q.offer(right);
                 grid[right.x][right.y]=false; 
              }
          }
           if(top.y>=0){
              if(grid[top.x][top.y]){
                  q.offer(top);
                 grid[top.x][top.y]=false; 
              }
          }
           if(down.y<grid[0].length){
              if(grid[down.x][down.y]){
                  q.offer(down);
                 grid[down.x][down.y]=false; 
              }
          }
      }
      
      
  }
}
