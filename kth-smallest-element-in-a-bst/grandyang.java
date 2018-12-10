// grandyang idea, to address the Follow up(the bst is modified often) that we need to find the kth smallest element frequently. 
//key point: instead of count the nodes each time, we save the count inside the node. however, when the tree is modified, we need to update the count field for each node that has been impacted. 
//beats 87.40%
class Solution {
    class MyTreeNode {
        int val,count;
        MyTreeNode left,right;
        public MyTreeNode(int x) {
            this.val = x;
            this.count = 1;
            this.left = null;
            this.right = null;
        }
    }
    private MyTreeNode build(TreeNode root) {
        if (root == null)
            return null;
        //create node from root
        MyTreeNode node = new MyTreeNode(root.val);
        node.left = build(root.left);
        node.right= build(root.right);
        //set count field
        if (node.left != null)
            node.count += node.left.count;
        if (node.right!= null)
            node.count += node.right.count;
        return node;
    }
    public int kthSmallest(TreeNode root, int k) {
        MyTreeNode node = build(root);
        return helper(node,k);
    }
    //shaun code with grandyang idea, beats 95%
    private int helper(MyTreeNode node, int k) {
        if (node == null)
            return -1;
        //divide and conquer
        if (node.left != null) {
            int cnt = node.left.count;
            if (k <= cnt) { //within left substree
                return helper(node.left,k);
            }else if (k > cnt + 1) { //in right substree
                //return helper(node.right,k); wont work
                return helper(node.right,k-cnt-1);
            }
            //now k == cnt + 1
            return node.val;
        }//else { //no left subtree, else not needed, since return for all if always return 
        if (k == 1)
            return node.val;
        //return helper(node.right); //wont work
        return helper(node.right,k-1);
        
    }
}

