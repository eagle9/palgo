//Your submission beats 35.00% Submissions!

public class Solution {
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */    
    public ArrayList<DirectedGraphNode> topSort(ArrayList<DirectedGraphNode> graph) {
        // map used to store in degree of all nodes
        HashMap<DirectedGraphNode, Integer> map = new HashMap();
        for (DirectedGraphNode node : graph) {
            for (DirectedGraphNode neighbor : node.neighbors) {
                if (map.containsKey(neighbor)) {
                    map.put(neighbor, map.get(neighbor) + 1);
                } else {
                    map.put(neighbor, 1); 
                }
            }
        }

        // initialize result to empty array
        ArrayList<DirectedGraphNode> result = new ArrayList<DirectedGraphNode>();

        //put all nodes whose in degree == 0 into BFS queue 
        Queue<DirectedGraphNode> q = new LinkedList<DirectedGraphNode>();
        for (DirectedGraphNode node : graph) {
            if (!map.containsKey(node)) {
                q.offer(node);
                result.add(node);
            }
        }

        //each time take one node from queue and put into result, decrease in degreeof each node that is pointed to from this node 
        while (!q.isEmpty()) {
            DirectedGraphNode node = q.poll();
            for (DirectedGraphNode n : node.neighbors) {
                map.put(n, map.get(n) - 1);
                // if in degree reaches 0, put into queue 
                if (map.get(n) == 0) {
                    result.add(n);
                    q.offer(n);
                }
            }
        }

        return result;
    }
}
