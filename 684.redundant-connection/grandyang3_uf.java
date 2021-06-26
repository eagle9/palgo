/*
最好的解法使用Union Find来做，论坛上清一色的都是用这种解法来做的，像博主用DFS和BFS这么清新脱俗的方法还真不多:) 其实Union Find的核心思想并不是很难理解，首先我们建立一个长度为(n+1)的数组root，由于这道题并没有明确的说明n是多少，只是说了输入的二位数组的长度不超过1000，那么n绝对不会超过2000，我们加1的原因是由于结点值是从1开始的，而数组是从0开始的，我们懒得转换了，就多加一位得了。我们将这个数组都初始化为-1，有些人喜欢初始化为i，都可以。开始表示每个结点都是一个单独的组，所谓的Union Find就是要让结点之间建立关联，比如若root[1] = 2，就表示结点1和结点2是相连的，root[2] = 3表示结点2和结点3是相连的，如果我们此时新加一条边[1, 3]的话，我们通过root[1]得到2，再通过root[2]得到3，说明结点1有另一条路径能到结点3，这样就说明环是存在的；如果没有这条路径，那么我们要将结点1和结点3关联起来，让root[1] = 3即可

grandyang idea3 union find, runtime 2ms, faster than 100%

*/
class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        //root[i] = j means that there is an edge from i to j
        int [] root = new int [1001]; //from problem assumption, 1001 or 2001 both work
        for (int [] edge: edges) {
            int x = find(root, edge[0]), y = find(root, edge[1]);
            if (x == y) return edge;
            root[x] = y;
        }
        return new int[] {};
    }
    private int find(int [] root, int i) {
        while (root[i] != 0) {
            i = root[i];
        }
        return i;
    }
}


/*
//grandyang idea3 union find
//runtime 4ms, faster than 100%
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> root(2001, -1);
        for (auto edge : edges) {
            int x = find(root, edge[0]), y = find(root, edge[1]);
            if (x == y) return edge;
            root[x] = y;
        }
        return {};
    }
    int find(vector<int>& root, int i) {
        while (root[i] != -1) {
            i = root[i];
        }
        return i;
    }
};
*/
