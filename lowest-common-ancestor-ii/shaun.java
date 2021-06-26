/**
 * Definition of ParentTreeNode:
 * 
 * class ParentTreeNode {
 *     public ParentTreeNode parent, left, right;
 * }
 */


public class Solution {
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
     //shaun's own based on jz idea, beats 49.80%
     //accepted upon 1st submission
    public ParentTreeNode lowestCommonAncestorII(ParentTreeNode root, ParentTreeNode A, ParentTreeNode B) {
        // write your code here
        List<ParentTreeNode> pathA = getPath2Root(A);
        List<ParentTreeNode> pathB = getPath2Root(B);
        //iterate pathA and pathB from tail
        
        int i = pathA.size()-1, j = pathB.size()-1;
        while (i >= 0 && j >= 0 && pathA.get(i) == pathB.get(j)) {
            i--;
            j--;
        }
        //!=
        return pathA.get(i+1);
    }
    private List<ParentTreeNode> getPath2Root(ParentTreeNode a) {
        List<ParentTreeNode> path = new ArrayList<>();
        while (a != null) {
            path.add(a);
            a = a.parent;
        }
        return path;
    }
}
