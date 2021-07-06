//idea is bfs traversal of the graph
class Solution {
    public boolean isBipartite(int[][] graph) {
        
        int [] color = new int[graph.length];
        //try all starting points
        for (int i = 0; i < graph.length; i++) {
            if (color[i] != 0) continue;
            //to color i
            color[i] = 1;
            Queue<Integer> queue = new LinkedList<>();
    
            queue.offer(i);
            while (!queue.isEmpty()) {
                int v = queue.poll();
                
                //check all neighbors
                for (int nei : graph[v]) {
                    if (color[v] == color[nei]) {
                        return false;
                    } 
                    
                    if (color[nei] == 0) {
                        color[nei] = -1 * color[v];
                        //continue to color
                        queue.offer(nei);
                    }
                }
                
            }
        }
        return true;
    }
}
