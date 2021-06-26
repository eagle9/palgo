/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val,Node _left,Node _right,Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
//https://www.programcreek.com/2014/06/leetcode-populating-next-right-pointers-in-each-node-ii-java/
//programcreek two level (head and cur pointers)
//runtime 1ms, faster than 77%, mem less than 99%
class Solution {
    public Node connect(Node root) {
        if(root == null) return root;

        Node lastHead = root;//prevous level's head 
        Node lastCurrent = null;//previous level's pointer
        Node currentHead = null;//currnet level's head 
        Node current = null;//current level's pointer

        while(lastHead!=null){
            lastCurrent = lastHead;

            while(lastCurrent!=null){
                //left child is not null
                if(lastCurrent.left!=null)    {
                    if(currentHead == null){
                        currentHead = lastCurrent.left;
                        current = lastCurrent.left;
                    }else{
                        current.next = lastCurrent.left;
                        current = current.next;
                    }
                }

                //right child is not null
                if(lastCurrent.right!=null){
                    if(currentHead == null){
                        currentHead = lastCurrent.right;
                        current = lastCurrent.right;
                    }else{
                        current.next = lastCurrent.right;
                        current = current.next;
                    }
                }

                lastCurrent = lastCurrent.next;
            }

            //update last head
            lastHead = currentHead;
            currentHead = null;
        }
        return root;
    }
}
