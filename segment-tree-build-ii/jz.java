/**
 * Definition of SegmentTreeNode:
 * public class SegmentTreeNode {
 *     public int start, end, max;
 *     public SegmentTreeNode left, right;
 *     public SegmentTreeNode(int start, int end, int max) {
 *         this.start = start;
 *         this.end = end;
 *         this.max = max
 *         this.left = this.right = null;
 *     }
 * }
 */
//jz micro course idea, beats 60%
public class Solution {
    /**
     * @param A: a list of integer
     * @return: The root of Segment Tree
     */
    public SegmentTreeNode build(int[] A) {
        // write your code here
        return helper(A, 0, A.length - 1);
    }
    private SegmentTreeNode helper(int [] A, int start, int end) {
        if (start > end) return null;
        if (start == end) return new SegmentTreeNode(start,end,A[start]);
        //start < end 
        int mid = start + (end - start)/2;
        SegmentTreeNode node = new SegmentTreeNode(start,end,A[start]);
        SegmentTreeNode left = helper(A,start,mid);
        SegmentTreeNode right= helper(A,mid+1,end);
        node.left = left;
        node.right = right;
        //remember to update node.max too
        if (left != null)
            node.max = Math.max(node.max, left.max);
        if (right!= null)
            node.max = Math.max(node.max, right.max);
        return node;
        
    }
}
