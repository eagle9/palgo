/**
 * Definition for Undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { 
 *         label = x;
 *         neighbors = new ArrayList<UndirectedGraphNode>(); 
 *     }
 * };
 */

//jz bfs beats 86.80%
public class Solution {
    /**
     * @param graph a list of Undirected graph node
     * @param s, t two Undirected graph nodes
     * @return an integer
     */
    public int sixDegrees(List<UndirectedGraphNode> graph,
                          UndirectedGraphNode s,
                          UndirectedGraphNode t) {
        // Write your code here
        if (s == t)
            return 0;
        //visist is a map that stores the number of steps/levels from the source node s
        Map<UndirectedGraphNode, Integer> visited = new HashMap<>();
        Queue<UndirectedGraphNode> queue = new LinkedList<>();
        
        queue.offer(s);
        visited.put(s, 0);
        while (!queue.isEmpty()) {
            UndirectedGraphNode node = queue.poll();
            int step = visited.get(node);
            //for (UndirectedGraphNode nb: node.neighbors)  //you can use this for each loop, but it is slower 
            int n = node.neighbors.size();
            for (int i = 0; i < n; i++) {
                UndirectedGraphNode nb = node.neighbors.get(i);
                if (visited.containsKey(nb)) {
                    continue;
                }
                visited.put(nb, step + 1);
                queue.offer(nb);
                if (nb == t) {
                    return step + 1;
                }
            }
        }
        
        return -1;
    }
}
