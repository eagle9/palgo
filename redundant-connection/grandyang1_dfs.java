//grandyang dfs, runtime 15ms, faster than 19%
/*

给我们了一个无向图，让我们删掉组成环的最后一条边，其实这道题跟之前那道Graph Valid Tree基本没什么区别，三种解法都基本相同。博主觉得老题稍微变一下就是一道新题，而onsite遇到原题的概率很小，大多情况下都会稍稍变一下，所以举一反三的能力真的很重要，要完全吃透一道题也不太容易，需要多下功夫。我们首先来看递归的解法，这种解法的思路是，每加入一条边，就进行环检测，一旦发现了环，就返回当前边。对于无向图，我们还是用邻接表来保存，建立每个结点和其所有邻接点的映射，由于两个结点之间不算有环，所以我们要避免这种情况 1->{2}, 2->{1}的死循环，所以我们用一个变量pre记录上一次递归的结点，比如上一次遍历的是结点1，那么在遍历结点2的邻接表时，就不会再次进入结点1了，这样有效的避免了死循环，使其能返回正确的结果

*/
class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        Map<Integer, Set<Integer>> m = new HashMap<>();
        for (int [] edge : edges) {
            if (hasCycle(edge[0], edge[1], m, -1)) return edge;
            Set<Integer> set = m.getOrDefault(edge[0], new HashSet<>());
            set.add(edge[1]);
            m.put(edge[0], set);
            
            //m[edge[1]].insert(edge[0]);
            set = m.getOrDefault(edge[1], new HashSet<>());
            set.add(edge[0]);
            m.put(edge[1], set);
        }
        return new int [] {};
    }
    //why pre??? avoid 1-2 and 2-1 cycle
    private boolean hasCycle(int cur, int target, Map<Integer,Set<Integer>> m, int pre) {
        Set<Integer> set = m.get(cur);
        if (set != null) {
            if (set.contains(target)) return true;
            for (int num : set) {
                if (num == pre) continue;
                if (hasCycle(num, target, m, cur)) return true;
            }
            
        }
        return false;
    }
}
