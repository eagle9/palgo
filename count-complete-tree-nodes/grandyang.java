/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
/*
grandyang idea1, shaun java code, runtime 2ms, faster than 100%
先来看递归的方法，思路是分别找出以当前节点为根节点的左子树和右子树的高度并对比，如果相等，则说明是满二叉树，直接返回节点个数，如果不相等，则节点个数为左子树的节点个数加上右子树的节点个数再加1(根节点)，其中左右子树节点个数的计算可以使用递归来计算
*/
class Solution1 {
    public int countNodes(TreeNode root) {
        int hLeft = 0, hRight = 0;
        TreeNode pLeft = root, pRight = root;
        while (pLeft != null) {
            hLeft++;
            pLeft = pLeft.left;
        }
        while (pRight != null) {
            hRight++;
            pRight = pRight.right;
        }
        if (hLeft == hRight) return pow(2,hLeft)-1;
        //hLeft != hRight
        return countNodes(root.left) + countNodes(root.right) + 1;
    }
    private int pow(int x, int n) {
        int res = 1;
        for (int i = 0; i < n; i++) {
            res *= x;
        }
        return res;
    }
}
//grandyang recursion 2, runtime 3ms, faster than 75%
class Solution {
    private int pow(int x, int n) {
        int res = 1;
        for (int i = 0; i < n; i++) {
            res *= x;
        }
        return res;
    }
    public int countNodes(TreeNode root) {
        int hLeft = leftHeight(root);
        int hRight = rightHeight(root);
        if (hLeft == hRight) return pow(2, hLeft) - 1;
        return countNodes(root.left) + countNodes(root.right) + 1;
    }
    int leftHeight(TreeNode root) {
        if (root == null) return 0;
        return 1 + leftHeight(root.left);
    }
    int rightHeight(TreeNode root) {
        if (root == null) return 0;
        return 1 + rightHeight(root.right);
    }
};
/*
class Solution {
public:
    int countNodes(TreeNode* root) {
        int hLeft = 0, hRight = 0;
        TreeNode *pLeft = root, *pRight = root;
        while (pLeft) {
            ++hLeft;
            pLeft = pLeft->left;
        }
        while (pRight) {
            ++hRight;
            pRight = pRight->right;
        }
        if (hLeft == hRight) return pow(2, hLeft) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
*/
