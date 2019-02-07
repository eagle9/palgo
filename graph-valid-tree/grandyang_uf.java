/*
grandyang union find idea, much simpler than jz union find
看Union Find的方法，这种方法对于解决连通图的问题很有效，思想是我们遍历节点，如果两个节点相连，我们将其roots值连上，这样可以帮助我们找到环，我们初始化roots数组为-1，然后对于一个pair的两个节点分别调用find函数，得到的值如果相同的话，则说明环存在，返回false，不同的话，我们将其roots值union上
runtime 0ms, faster than 100%
*/
class Solution {
    public boolean validTree(int n, int[][] edges) {
        if (edges.length != n-1) return false;
        int [] roots = new int[n];
        for (int [] a : edges) {
            int x = find(roots, a[0]), y = find(roots, a[1]);
            if (x == y) return false;
            roots[x] = y;
        }
        return true;
    }
    private int find(int [] roots, int i) {
        while (roots[i] != 0) i = roots[i];
        return i;
    }
}
