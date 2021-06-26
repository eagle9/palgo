/**
 * Definition for graph node.
 * class GraphNode {
 *     int label;
 *     ArrayList<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { 
 *         label = x; neighbors = new ArrayList<UndirectedGraphNode>(); 
 *     }
 * };
 */
 //jz bidirectional bfs, beats 79.51%
public class Solution {
    /**
     * @param graph: a list of Undirected graph node
     * @param A: nodeA
     * @param B: nodeB
     * @return:  the length of the shortest path
     */
    public int shortestPath(List<UndirectedGraphNode> graph, UndirectedGraphNode A, UndirectedGraphNode B) {
        if (graph == null || graph.size() == 0) {
            return 0;
        }
        
        if (A == B) {
            return 0;
        }
        Queue<UndirectedGraphNode> sQueue = new LinkedList<>();
        Set<UndirectedGraphNode> sHash = new HashSet<>();
        sQueue.offer(A);
        sHash.add(A);
        
        Queue<UndirectedGraphNode> eQueue = new LinkedList<>();
        Set<UndirectedGraphNode> eHash = new HashSet<>();
        eQueue.offer(B);
        eHash.add(B);
        
        int len = 0;
        while (!sQueue.isEmpty() || !eQueue.isEmpty()) {
            len++;
            int sSize = sQueue.size();
            for (int sLevel = 0; sLevel < sSize; ++sLevel) {
                UndirectedGraphNode curt = sQueue.poll();
                for (UndirectedGraphNode neighbor : curt.neighbors) {
                    if (sHash.contains(neighbor)) {
                        continue;
                    }
                    if (eHash.contains(neighbor)) {
                        return len;
                    }
                    sQueue.offer(neighbor);
                    sHash.add(neighbor);
                }
            }
            len++;
            int eSize = eQueue.size();
            for (int eLevel = 0; eLevel < eSize; ++eLevel) {
                UndirectedGraphNode curt = eQueue.poll();
                for (UndirectedGraphNode neighbor : curt.neighbors) {
                    if (eHash.contains(neighbor)) {
                        continue;
                    }
                    if (sHash.contains(neighbor)) {
                        return len;
                    }
                    eQueue.offer(neighbor);
                    eHash.add(neighbor);
                }
            }
        }
        return -1;
    }
}
