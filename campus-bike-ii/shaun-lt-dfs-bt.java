/*dfs + pruning

https://www.cnblogs.com/EdwardLiu/p/11617637.html

//runtime 226ms, faster than 31%, mem less than 100%

sum of the distance between worker and assigned bike is minimized

*/
class Solution {
    int minDist = Integer.MAX_VALUE;
    
    public int assignBikes(int[][] workers, int[][] bikes) {
        dfs(workers, bikes, new boolean[bikes.length], 0, 0);    
        return minDist;
    }
    //used -- bike index used or not
    //cur -- cur index of worker
    //distance -- sum of distance so far
    public void dfs(int[][] workers, int[][] bikes, boolean[] used, int cur, int distance) {
        //cur index of worker
        if (cur == workers.length) {
            minDist = Math.min(minDist, distance);
            return;
        }
        //current distance already > minDis, no recur, prunning 
        if (distance > minDist) return;
        
        //for worker index cur, try all bikes not used yet
        for (int i = 0; i < used.length; i ++) {
            if (used[i]) continue;
            used[i] = true; //try assign bike i to worker cur
            //the remaining problem is similar
            dfs(workers, bikes, used, cur + 1, distance + manhattanDis(workers[cur], bikes[i]));
            used[i] = false;
        }
    }
    
    public int manhattanDis(int[] worker, int[] bike) {
        return Math.abs(worker[0] - bike[0]) + Math.abs(worker[1] - bike[1]);
    }
}
