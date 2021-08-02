/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x;}
    /*
    @Override
        public int hashCode() {return val;}
    @Override 
        public boolean equals(Object other) {
            TreeNode o = (TreeNode) other;
            return val == o.val;
        }*/
    }
    
class Solution {
    
  Map<TreeNode, List<TreeNode>> g = new HashMap<>();
  
  void buildGraph(TreeNode parent, TreeNode child) {      
    if (parent != null) {
      /*  g.putIfAbsent(parent, new ArrayList<>());
        g.putIfAbsent(child, new ArrayList<>());
      g.get(parent).add(child);
      g.get(child).add(parent);
      */
      g.computeIfAbsent(parent, k ->new ArrayList<>()).add(child);
      g.computeIfAbsent(child, k->new ArrayList<>()).add(parent);  
    }
    if (child.left != null) buildGraph(child, child.left);
    if (child.right != null) buildGraph(child, child.right);
  }
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        
        buildGraph(null, root);    
        List<Integer> ans = new ArrayList<>();
        Set<TreeNode> seen = new HashSet<>();  
        Queue<TreeNode> q = new LinkedList<>();
        seen.add(target);
        q.offer(target);
        int k = 0;
        while (!q.isEmpty() && k <= K) {
          int s = q.size();
          //while (s-- > 0) {
          //at level k
          for (int i = 0; i < s; i++) {
            TreeNode node = q.poll();
            if (k == K) ans.add(node.val);    
            for (TreeNode child : g.getOrDefault(node, new ArrayList<>())) {
              if (seen.contains(child)) continue;
              q.offer(child);
              seen.add(child);
            }
          }
          ++k;
        }
        return ans;
    }
    
}

