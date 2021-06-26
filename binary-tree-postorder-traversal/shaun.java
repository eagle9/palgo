//shaun modified from preorder stack, beats 90%
/*key points:
1) idea is to reverse preorder
2) draw for simple case 
3) not only reverse root visit order, but aslo reverse left and right order

*/

class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> values = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        
        TreeNode curt = root;
        while (curt != null || !stack.isEmpty()) {
            while (curt != null ) {
                //check curt
                values.add(0,curt.val);
                stack.push(curt);
                //curt = curt.left;
                curt = curt.right;
            }
            //curt == null;
            curt = stack.pop();
            //curt = curt.right;
            curt = curt.left;
        }
        return values;
    }
}

