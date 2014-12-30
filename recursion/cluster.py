'''
Created on Dec 29, 2014

@author: XY1267
'''
a = [[1, 1, 1], [0, 0, 0]]
a = [[1,0,1],
  [0,1,0],
  [1,1,1]]
ROWS = len(a)
COLS = len(a[0])
print ROWS, COLS
#range(N) produce list 0 .... N-1
#python true and false is True and False
#|| is or && is and 
# no ++ or --, use += and -=
used = [[False for _ in range(COLS)] for _ in range(ROWS)]
print used
def grow_cluster(i,j):
    if (i < 0 or i >= ROWS): return 0
    if (j < 0 or j >= COLS): return 0
    if (a[i][j] == 1 and not used[i][j]):
            used[i][j]= True
            grow_cluster(i-1,j) # //up
            grow_cluster(i+1,j) # //down
            grow_cluster(i,j-1) #//left
            grow_cluster(i,j+1) # //right
            return 1
    else:  #  //white or already counted in some previous found cluster
            return 0

def demo():
    count = 0
    for i in range(ROWS):
        for j in range(COLS):
            count += grow_cluster(i,j)
    print count
"""
/**
 * 
 * @author XY1267
 *Write a function that given a 2d array will return the number of shapes that are present.

 [[1,0,1],
  [0,1,0],
  [1,1,1]]
  3
  left top corner dot, right top corner dot, bottom 4 pixel cluster
 
  [[1, 1, 1],
   [0, 0, 0]]
  1
 */
class Cluster {
    int a [][] = {  {1,0,1 },   {0,1,0  }, {1,1,1}};
    //int a [][] = {{1, 1, 1}, {0, 0, 0}};
    int ROWS = a.length;
    int COLS = a[0].length;

    boolean [][] used = new boolean[ROWS][COLS];
    
    int count() {

        int count = 0;
        if (a == null) return count;
        for (int i =0; i < ROWS; i++)  {
            for (int j = 0; j< COLS; j++) {
                count += grow_cluster(i,j);
            }
        }
        return count;
    }
    //tell me if there is a cluster at a[i][j]
    int  grow_cluster(int i, int j) {
        if (i < 0 || i >= ROWS) return 0; //j>ROWS
        if (j < 0 || j >= COLS) return 0;
        
        if (a[i][j] == 1 && !used[i][j]) {
            used[i][j]= true;
            grow_cluster(i-1,j); //up
            grow_cluster(i+1,j); //down
            grow_cluster(i,j-1); //left
            grow_cluster(i,j+1); //right
            return 1;
        }else {  //white or already counted in some previous found cluster
            return 0;
        }
    }
    public static void main(String [] args) {
        
        Cluster cluster = new Cluster();
        System.out.println(cluster.count());
    }
}
"""