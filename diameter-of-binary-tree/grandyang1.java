/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
//grandyang idea1, shaun java code, beats 17%
class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        //root != null now
        int hLeft = getHeight(root.left);
        int hRight = getHeight(root.right);
        int dia = hLeft + hRight;
        int diaLeft = diameterOfBinaryTree(root.left);
        int diaRight= diameterOfBinaryTree(root.right);
        return Math.max(dia, Math.max(diaLeft, diaRight));
    }
    private int getHeight(TreeNode node) {
        if (node == null) return 0;
        if (m.containsKey(node)) return m.get(node);
        int left = getHeight(node.left);
        int right = getHeight(node.right);
        int h = 1 + Math.max(left, right);
        m.put(node,h);
        return h;
    }
    
    private Map<TreeNode,Integer> m = new HashMap<>();
}

/*
//grandyang idea1, beats 29%
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int res = getHeight(root->left) + getHeight(root->right);
        return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    int getHeight(TreeNode* node) {
        if (!node) return 0;
        if (m.count(node)) return m[node];
        int h = 1 + max(getHeight(node->left), getHeight(node->right));
        return m[node] = h;
    }

private:
    unordered_map<TreeNode*, int> m;
};
*/
