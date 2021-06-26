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
 //jz idea, beats 49%
public class Solution {
    /**
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    public void modify(SegmentTreeNode root, int index, int value) {
        // write your code here
        if(root.start == index && root.end == index) { // 查找到
            root.max = value;
            return;
        }
        
        // 查询
        int mid = (root.start + root.end) / 2;
        //index is inside the left subtree
        if(root.start <= index && index <=mid) {
            modify(root.left, index, value);
        }
        
        //index is inside the right subtree
        if(mid < index && index <= root.end) {
            modify(root.right, index, value);
        }
        //更新 --- don't forget this
        root.max = Math.max(root.left.max, root.right.max);
    }
}
