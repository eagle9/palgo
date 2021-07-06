package org.voyiger.algo;

import org.junit.Test;

import java.util.Stack;

public class ClosestBinarySearchTreeValue {
    //in order traversal with stack
    public int closestValue(TreeNode root, double target) {
        double d = Double.MAX_VALUE;
        int res = 0;
        Stack<TreeNode> s = new Stack();
        TreeNode p = root;
        while (p != null || !s.isEmpty()) {
            while (p != null) {
                s.push(p);
                p = p.left;
            }
            p = s.pop();
            if (d > Math.abs(target - p.val)) {
                d = Math.abs(target - p.val);
                res = p.val;
            }
            p = p.right;
        }
        return res;
    }
    //binary search, very smart
    int closestValue2(TreeNode root, double target) {
        int res = root.val;
        while (root != null) {
            if (Math.abs(res - target) >= Math.abs(root.val - target)) {
                res = root.val;
            }
            //if target < root.val, the smaller diff should in left subtree
            root = target < root.val ? root.left : root.right;
        }
        return res;
    }

    @Test
    public void test(){
        int [] a = {4,2,5,1,3};
        TreeNode root = TreeNode.fromArray(a);
        double target = 3.714286;
        TreeNode.printByLevel(root);
        int res = closestValue(root, target);
        System.out.println("res = " + res);
    }
}

