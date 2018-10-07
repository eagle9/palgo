//Your submission beats 70.60% Submissions!

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

        // init sorted list
        ArrayList<DirectedGraphNode> result = new ArrayList<>();

        // put nodes whose indegree == 0 into queue
        Queue<DirectedGraphNode> q = new LinkedList<>();
        for (DirectedGraphNode node : graph) {
            if (!indegree.containsKey(node)) { //indegree = 1 or 1+ if has node
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
