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
 //jz idea, beats 37%
public class Solution {
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    public int query(SegmentTreeNode root, int start, int end) {
        // write your code here
        if(start == root.start && root.end == end) { // right on target with the root 
            return root.max;
        }
        
        
        int mid = (root.start + root.end)/2;
        int leftmax = Integer.MIN_VALUE, rightmax = Integer.MIN_VALUE;
        // 左子区
        if(start <= mid) {
            if( end <= mid) { // start,end is inside left subtree
                leftmax = query(root.left, start, end);
            } else { // mid < end ==> only start,mid inside left subtree
                leftmax =  query(root.left, start, mid);  
            }
            
        }
        // 右子区
        if(mid < end) { 
            if(mid < start) { //start end in right tree
                rightmax = query(root.right, start, end);
            } else { //start <= mid,   only  mid+1,end in right tree 
                rightmax = query(root.right, mid+1, end);
            }
            
        }  
        // else 就是不相交
        return Math.max(leftmax, rightmax);
    }
}
