/*
grandyang idea2 bfs, runtime 26ms, faster than 10%
既然递归能做，一般来说迭代也木有问题。但是由于BFS的遍历机制和DFS不同，所以没法采用利用变量pre来避免上面所说的死循环(不是很确定，可能是博主没想出来，有做出来的请在评论区贴上代码)，所以我们采用一个集合来记录遍历过的结点，如果该结点已经遍历过了，那么直接跳过即可，否则我们就把该结点加入queue和集合，继续循环
*/
class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        Map<Integer, Set<Integer>> m = new HashMap<>();
        /*  you have to build the graph on the fly to ensure return the last redundant edge
        for (int [] edge : edges) {
            m.putIfAbsent(edge[0], new HashSet<>());
            m.get(edge[0]).add(edge[1]);
            
            m.putIfAbsent(edge[1], new HashSet<>());
            m.get(edge[1]).add(edge[0]);
        }*/
        
        for (int [] edge : edges) {
            Queue<Integer> q = new LinkedList<>();
            q.offer(edge[0]);
            Set<Integer> visited = new HashSet<>(); 
            visited.add(edge[0]);
            
            while (!q.isEmpty()) {
                Integer t = q.poll();
                Set<Integer> set = m.get(t);
                if (set == null) continue;
                
                if (set.contains(edge[1])) return edge;
                for (int num : set) {
                    if (visited.contains(num)) continue;
                    q.offer(num);
                    visited.add(num);
                }
            }
            //build the graph on the fly, why??
            m.putIfAbsent(edge[0], new HashSet<>());
            m.get(edge[0]).add(edge[1]);
            
            m.putIfAbsent(edge[1], new HashSet<>());
            m.get(edge[1]).add(edge[0]);
            
        }
        return new int [] {};
    }
}
