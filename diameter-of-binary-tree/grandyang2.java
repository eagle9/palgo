/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
//grandyang idea2, beats 30%
class Solution2 {
    public int diameterOfBinaryTree(TreeNode root) {
        maxDepth(root);
        return dia;
    }
    private int maxDepth(TreeNode node) {
        if (node == null) return 0;
        int dLeft = maxDepth(node.left);
        int dRight = maxDepth(node.right);
        dia = Math.max(dia, dLeft + dRight);
        return 1 + Math.max(dLeft, dRight);
    }
    private int dia = 0;
}
//grandyang idea3, with map, actuals does not speed up 
class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
        maxDepth(root);
        return dia;
    }
    private int maxDepth(TreeNode node) {
        if (node == null) return 0;
        if (m.containsKey(node)) return m.get(node);
        
        int dLeft = maxDepth(node.left);
        int dRight = maxDepth(node.right);
        dia = Math.max(dia, dLeft + dRight);
        int d = 1 + Math.max(dLeft, dRight);
        m.put(node, d);
        return d;
    }
    private int dia = 0;
    private Map<TreeNode, Integer> m = new HashMap<>();
}

/*
//grandyang idea2, maxDepth at a node, update diameter in the process
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        maxDepth(root, res);
        return res;
    }
    int maxDepth(TreeNode* node, int& res) {
        if (!node) return 0;
        int left = maxDepth(node->left, res);
        int right = maxDepth(node->right, res);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};
*/
