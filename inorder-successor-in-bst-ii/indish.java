/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
};
*/
/*
Runtime: 4 ms, faster than 99.66% of Java online submissions for Inorder Successor in BST II.
Memory Usage: 79 MB, less than 54.40% of Java online submissions for Inorder Successor in BST II.
If the given node has a right, then the left most node on the right side must be the successor.

If the given node is on the left side and its parent's right is pointing to the given node, then we must find a parent node whose left is current node for it to become the successor.

Take a look the example 3 provided in the question. Observe the successor for 13.
Think about successor of 18 in the same example if it didn't have any child nodes.
https://leetcode.com/problems/inorder-successor-in-bst-ii/discuss/239399/JAVA-iterative-Beats-100-4ms-not-looking-up-node-values.-Detailed-explanation.

not yet understand the problem and solution, todo 

*/
class Solution {
    public Node inorderSuccessor(Node x) {
        if(x == null) return null;
        
        if(x.right != null) {
            x = x.right;
            while(x != null && x.left != null) {
                x = x.left;
            }
            return x;
        }
        
        while(x != null){
            if(x.parent == null)
                return null;
                
            if(x.parent.left == x)
                return x.parent;
            
            else {
                x = x.parent;
            }
                
        }
        
        return x;
    }
}
