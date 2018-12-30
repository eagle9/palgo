public class Solution {
    //fuxuemingzhu, beats 5%
    StringBuilder spre = new StringBuilder();
    StringBuilder tpre = new StringBuilder();
    public boolean isSubtree(TreeNode s, TreeNode t) {
        preOrder(s, spre.append(","));
        preOrder(t, tpre.append(","));
        System.out.println(spre.toString());
        System.out.println(tpre.toString());
        return spre.toString().contains(tpre.toString());
    }
    public void preOrder(TreeNode root, StringBuilder str){
        if(root == null){
            str.append("#,");
            return;
        }
        str.append(root.val).append(",");
        preOrder(root.left, str);
        preOrder(root.right, str);
    }
}
/*
--------------------- 
作者：负雪明烛 
来源：CSDN 
原文：https://blog.csdn.net/fuxuemingzhu/article/details/71440802 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
