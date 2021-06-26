/**
 * Definition for Directed graph.
 * class DirectedGraphNode {
 *     int label;
 *     ArrayList<DirectedGraphNode> neighbors;
 *     DirectedGraphNode(int x) { label = x; neighbors = new ArrayList<DirectedGraphNode>(); }
 * };
 */

//lintcode topological sorting
//Your submission beats 78.60% Submissions!

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
            for (DirectedGraphNode neighbor : node.neighbors) {
                if (indegree.containsKey(neighbor)) {
                    indegree.put(neighbor, indegree.get(neighbor) + 1);
                } else { //init
                    indegree.put(neighbor, 1); 
                }
            }
        }
		//note: from the code above, some nodes might not be in indegree

        ArrayList<DirectedGraphNode> result = new ArrayList<>();

        // put nodes whose indegree == 0 into queue
        Queue<DirectedGraphNode> q = new LinkedList<>();
        for (DirectedGraphNode node : graph) {
            if (!indegree.containsKey(node)) { //indegree == 0
                q.offer(node);
                result.add(node);
            }
        }

        // poll one node from queue, -1 indegree for all its neighbors
        while (!q.isEmpty()) {
            DirectedGraphNode node = q.poll();
			//node has been used in the top sort list, now all it neighbors' indegree --
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
