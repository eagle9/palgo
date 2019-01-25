//jz using SegmentTree, beats 54.60%
public class Solution {
    /* you may need to use some attributes here */
    
     class SegmentTreeNode {
        public int start, end;
        public int sum;
        public SegmentTreeNode left, right;
        public SegmentTreeNode(int start, int end, int sum) {
              this.start = start;
              this.end = end;
              this.sum = sum;
              this.left = this.right = null;
        }
    }
    SegmentTreeNode root;
    public SegmentTreeNode build(int start, int end, int[] A) {
        // write your code here
        if(start > end) {  // check core case
            return null;
        }
        
        SegmentTreeNode root = new SegmentTreeNode(start, end, 0);
        
        if(start != end) {
            int mid = (start + end) / 2;
            root.left = build(start, mid, A);
            root.right = build(mid+1, end, A);
            
            root.sum = root.left.sum + root.right.sum;
        } else {
            root.sum =  A[start];
            
        }
        return root;
    }
    public int querySegmentTree(SegmentTreeNode root, int start, int end) {
        // write your code here
        if(start == root.start && root.end == end) { // equal 
            return root.sum;
        }
        
        
        int mid = (root.start + root.end)/2;
        int leftsum = 0, rightsum = 0;
        // left 
        if(start <= mid) {
            if( mid < end) { // split
                leftsum =  querySegmentTree(root.left, start, mid);
            } else { // contain 
                leftsum = querySegmentTree(root.left, start, end);
            }
        }
        // right 
        if(mid < end) { // split 3
            if(start <= mid) {
                rightsum = querySegmentTree(root.right, mid+1, end);
            } else { //  包含 
                rightsum = querySegmentTree(root.right, start, end);
            } 
        }  
        // else not intersect
        return leftsum + rightsum;
    }
    public void modifySegmentTree(SegmentTreeNode root, int index, int value) {
        // write your code here
        if(root.start == index && root.end == index) { // found
            root.sum = value;
            return;
        }
        
        // query
        int mid = (root.start + root.end) / 2;
        if(root.start <= index && index <=mid) {
            modifySegmentTree(root.left, index, value);
        }
        
        if(mid < index && index <= root.end) {
            modifySegmentTree(root.right, index, value);
        }
        //update
		// remember propogate sum up to root
        root.sum = root.left.sum + root.right.sum;
    }
    /**
     * @param A: An integer array
     */
    public Solution(int[] A) {
        // write your code here
        root = build(0, A.length-1, A);
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    public long query(int start, int end) {
        // write your code here
        return querySegmentTree(root, start ,end);
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    public void modify(int index, int value) {
        // write your code here
        modifySegmentTree(root, index, value);
    }
}
