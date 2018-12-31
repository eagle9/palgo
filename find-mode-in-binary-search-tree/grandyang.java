/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
//grandyang idea, shaun java code, beats 77%
//idea is inorder produces sorted values, count repeated values, keep a maxCnt and update it
class Solution {
    public int[] findMode(TreeNode root) {
        List<Integer> res  = new ArrayList<>();
        
        inorder(root, res);
        int n = res.size();
        int [] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = res.get(i);
        }
        return a;
    }
    private int cnt = 1;
    private int maxCnt = 0;
    private TreeNode pre = null;
    private void inorder(TreeNode node, List<Integer> res) {
        if (node == null) return;
        inorder(node.left, res);
        
        //deal with node
        if (pre != null) {
            if (node.val == pre.val) cnt++;
            else cnt = 1;
        }
        if (cnt >= maxCnt) {
            if (cnt > maxCnt)
                res.clear();
            res.add(node.val);
            maxCnt = cnt;
        }
        pre = node;
        
        inorder(node.right, res);
    }
}

/*
detailed idea:
题目中的follow up说了让我们不用除了递归中的隐含栈之外的额外空间，那么我们就不能用哈希表了，不过这也不难，由于是二分搜索树，那么我们中序遍历出来的结果就是有序的，这样我们只要比较前后两个元素是否相等，就等统计出现某个元素出现的次数，因为相同的元素肯定是都在一起的。我们需要一个结点变量pre来记录上一个遍历到的结点，然后mx还是记录最大的次数，cnt来计数当前元素出现的个数，我们在中序遍历的时候，如果pre不为空，说明当前不是第一个结点，我们和之前一个结点值比较，如果相等，cnt自增1，如果不等，cnt重置1。如果此时cnt大于了mx，那么我们清空结果res，并把当前结点值加入结果res，如果cnt等于mx，那我们直接将当前结点值加入结果res，然后mx赋值为cnt。最后我们要把pre更新为当前结点，
*/

