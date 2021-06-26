/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 
 
 shaun bfs idea from c++ to java
 using array of string split to store tokens
 error prone, then use iterator for cleaner code, 
 
 Runtime: 18 ms, faster than 36.08% of Java online submissions for Serialize and Deserialize Binary Tree.
Memory Usage: 41.8 MB, less than 19.05% of Java online submissions for Serialize and Deserialize Binary Tree.
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder out = new StringBuilder();
        Queue<TreeNode> q = new LinkedList<>();
        if (root != null) q.offer(root);
        while (!q.isEmpty()) {
            TreeNode t = q.poll();
            if (t!=null) {
                out.append(t.val + " ");
                q.offer(t.left);
                q.offer(t.right);
            } else {
                out.append("# ");
            }
        }
        return out.toString();
    }
    
    // Decodes your encoded data to tree.
    //cleaner code using iterator
    public TreeNode deserialize(String data) {
        if (data.length() ==0) return null; //NULL okay too
        
        Queue<TreeNode> q = new LinkedList<>();
        //Iterator<String> it = Arrays.stream(data.split(" ")).iterator();
        Iterator<String> it = Arrays.asList(data.split(" ")).iterator();
        String token = it.next();
        TreeNode root = new TreeNode(Integer.valueOf(token));
        TreeNode cur = root;
        q.offer(root);
        
        while (!q.isEmpty()) {
            
            TreeNode node = q.poll();
            for (int i = 0; i < 2 &&it.hasNext(); i++) {
                token = it.next();
                if (!token.equals("#")) {
                    cur = new TreeNode(Integer.valueOf(token));
                    q.offer(cur);
                    switch(i){
                        case 0: node.left = cur; break;
                        case 1: node.right = cur; break;
                    }
                    
                }
            }
        }
        return root;

    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize2(String data) {
        if (data.length() ==0) return null; //NULL okay too
        
        Queue<TreeNode> q = new LinkedList<>();
        String [] a = data.split(" ");
        int i = 0;
        TreeNode root = new TreeNode(Integer.valueOf(a[i]));
        TreeNode cur = root;
        q.offer(root);
        i++;
        while (!q.isEmpty()) {
            
            if (i == a.length) break;
            String token = a[i];
            //if (token.length() == 0) continue;
            
            TreeNode node = q.poll();
            if (!token.equals("#")) {
                cur = new TreeNode(Integer.valueOf(token));
                q.offer(cur);
                node.left = cur;
            }
            i++;
            if (i == a.length) break;
            token = a[i];
            //if (token.length() == 0) continue;
            if (!token.equals("#")) {
                cur = new TreeNode(Integer.valueOf(token));
                q.offer(cur);
                node.right = cur;
            }
            i++;
        }
        return root;

    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
