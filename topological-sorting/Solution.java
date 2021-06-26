/**
 * Definition for Directed graph.
 * class DirectedGraphNode {
 *     int label;
 *     ArrayList<DirectedGraphNode> neighbors;
 *     DirectedGraphNode(int x) { label = x; neighbors = new ArrayList<DirectedGraphNode>(); }
 * };
 */

// use jdk 8 map.putIfAbsent, faster and clener code
//Your submission beats 91.60% Submissions!

public class Solution {
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */    
    public ArrayList<DirectedGraphNode> topSort(ArrayList<DirectedGraphNode> graph) {
        // map used to store the indegree of each node
        HashMap<DirectedGraphNode, Integer> indegree = new HashMap();
        //node -> neighbors
        for (DirectedGraphNode node : graph) {
            indegree.putIfAbsent(node,0);
            for (DirectedGraphNode nb : node.neighbors) {
                indegree.putIfAbsent(nb,0);
                indegree.put(nb, indegree.get(nb)+1);
            }
        }

        // init sorted list
        ArrayList<DirectedGraphNode> result = new ArrayList<>();

        // put nodes whose indegree == 0 into queue
        Queue<DirectedGraphNode> q = new LinkedList<>();
        for (DirectedGraphNode node : graph) {
            
            //if (!indegree.containsKey(node)) { //indegree == 0
            if (indegree.get(node) == 0) {
                q.offer(node);
                result.add(node);
            }
        }

        // poll one node from queue, -1 indegree for all its neighbors
        while (!q.isEmpty()) {
            DirectedGraphNode node = q.poll();
            for (DirectedGraphNode nb : node.neighbors) {
                indegree.put(nb, indegree.get(nb) - 1);
                if (indegree.get(nb) == 0) {
                    result.add(nb);
                    q.offer(nb);
                }
            }
        }

        return result;
    }
}
