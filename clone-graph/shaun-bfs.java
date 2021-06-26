/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

Runtime: 27 ms, faster than 72.85% of Java online submissions for Clone Graph.
Memory Usage: 40 MB, less than 5.88% of Java online submissions for Clone Graph.
*/


//shaun adapted from python bfs, 40% tests passed, wrong answer
//fix a typo, then accepted, beats 92.00%, same idea as jz
public class Solution {
    public Node cloneGraph(Node node){
        
        if (node == null) 
            return null; 
            
        //use bfs algorithm to traverse the graph and get all nodes.
        Set<Node> nodes = getNodes(node);
        
        //copy nodes, store the old->new mapping information in a hashmap
        Map<Node, Node> mapping = new HashMap<>(); 
        for (Node n : nodes) {
            mapping.put(n, new Node(n.val));
        }
        
        //copy neighbors(edges)
        for (Node n : nodes) {
            Node new_node = mapping.get(n);
            for (Node neighbor : n.neighbors) {
                Node new_neighbor = mapping.get(neighbor);
                new_node.neighbors.add(new_neighbor);
            }
        }
        
        return mapping.get(node);
    }

    //bfs traversal of graph return set of nodes    
    //return a set or list? set does not order, we want bfs order
    //Set<UndirectedGraphNode> getNodes(UndirectedGraphNode node) {  --> wrong answer
    Set<Node> getNodes(Node node) {
        Queue<Node> q = new ArrayDeque<>();
        q.offer(node);
        
        
        Set<Node> res = new HashSet<>();
        res.add(node);
        while (!q.isEmpty()) {
            Node head = q.poll();
            for (Node neighbor : head.neighbors) {
                if (!res.contains(neighbor)) {
                    res.add(neighbor);
                    q.offer(neighbor);
                }
            }
        }
        return res;
    }
}

