/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     ArrayList<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
//shaun adapted from python bfs, 40% tests passed, wrong answer

public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node){
        UndirectedGraphNode root = node;
        if (node == null) 
            return null; 
            
        //use bfs algorithm to traverse the graph and get all nodes.
        Set<UndirectedGraphNode> nodes = getNodes(node);
        
        //copy nodes, store the old->new mapping information in a hashmap
        Map<UndirectedGraphNode, UndirectedGraphNode> mapping = new HashMap<>(); 
        for (UndirectedGraphNode n : nodes) {
            mapping.put(n, new UndirectedGraphNode(n.label));
        }
        
        //copy neighbors(edges)
        for (UndirectedGraphNode n : nodes) {
            UndirectedGraphNode new_node = mapping.get(node);
            for (UndirectedGraphNode neighbor : n.neighbors) {
                UndirectedGraphNode new_neighbor = mapping.get(neighbor);
                new_node.neighbors.add(new_neighbor);
            }
        }
        
        return mapping.get(root);
    }

    //bfs traversal of graph return set of nodes    
    //return a set or list? set does not order, we want bfs order
    //Set<UndirectedGraphNode> getNodes(UndirectedGraphNode node) {  --> wrong answer
    Set<UndirectedGraphNode> getNodes(UndirectedGraphNode node) {
        Queue<UndirectedGraphNode> q = new ArrayDeque<>();
        q.offer(node);
        
        
        Set<UndirectedGraphNode> res = new HashSet<>();
        res.add(node);
        while (!q.isEmpty()) {
            UndirectedGraphNode head = q.poll();
            for (UndirectedGraphNode neighbor : head.neighbors) {
                if (!res.contains(neighbor)) {
                    res.add(neighbor);
                    q.offer(neighbor);
                }
            }
        }
        return res;
    }
}
