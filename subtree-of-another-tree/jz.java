public class Solution {
    /**
     * @param s: the s' root
     * @param t: the t' root
     * @return: whether tree t has exactly the same structure and node values with a subtree of s
     */
    //jz,shaun modified for natural thinking,  beats 37%
    public boolean isSubtree(TreeNode s, TreeNode t) {
        // Write your code here
        //since s.left and s.right will be used for recursion, do case for null
        if (s == null) {
            return t == null;
        }
        
        //corner case, same tree
        //if (s.val == t.val && isSametree(s, t)){
        if (isSametree(s,t)) {
            return true;
        }
        
        //reduce the problem to smaller tree
        return isSubtree(s.left, t) | isSubtree(s.right, t);
    }
    
    private boolean isSametree(TreeNode s, TreeNode t) {
        if (s == null && t == null) {
            return true;
        }
        if (t == null && s != null){
            return false;
        }
        if (s == null && t != null) {
            return false;
        }
        
        //now s != null and t!= null
        if (s.val != t.val){
            return false;
        }
        
        return isSametree(s.left, t.left) & isSametree(s.right, t.right);
    }
}
