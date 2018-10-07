/*
Definition for a undirected graph node
class UndirectedGraphNode {
    int lable;
    List<Integer> neighbors;
    UndirectedGraphNode(int x)  {
        this.label = x
        this.neighbors = new ArrayList<>();
    }
}
*/

public class Solution {
    void cloneGraph(UndirectedGraphNode node){
        UndirectedGraphNode root = node;
        if (node == null) 
            return null; 
            
        //use bfs algorithm to traverse the graph and get all nodes.
        List<UndirectedGraphNode> nodes = getNodes(node);
        
        //copy nodes, store the old->new mapping information in a hashmap
        Map<UndirectedGraphNode, UndirectedGraphNode> mapping = new HashMap<>(); 
        for (UndirectedGraphNode node : nodes) {
            mapping.put(node, new UndirectedGraphNode(node.label));
        }
        
        //copy neighbors(edges)
        for (UndirectedGraphNode node : nodes) {
            UndirectedGraphNode new_node = mapping.get(node);
            for (UndirectedGraphNode neighbor : node.neighbors) {
                new_neighbor = mapping.get(neighbor);
                new_node.neighbors.add(new_neighbor);
            }
        }
        
        return mapping.get(root);
    }

    //bfs traversal of graph return set of nodes    
    Set<UndirectedGraphNode> getNodes(UndirectedGraphNode node) {
        Queue<UndirectedGraphNode> q = new ArrayDeque<>();
        Set<UndirectedGraphNode> result = new Hashset<>();
        result.add(node);
        while (!q.isEmpty()) {
            UndirectedGraphNode head = q.poll();
            for (UndirectedGraphNode neighbor : head.neighbors) {
                if (!result.contains(neighbor)) {
                    result.add(neighbor);
                    q.offer(neighbor);
                }
            }
        }
        return result;
    }
}
