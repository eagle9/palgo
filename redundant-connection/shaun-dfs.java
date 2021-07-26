class Solution {
    Set<Integer> seen = new HashSet();
    int MAX_EDGE_VAL = 1000; //max number of edges allowed at each node

    public int[] findRedundantConnection(int[][] edges) {
        ArrayList<Integer>[] graph = new ArrayList[MAX_EDGE_VAL + 1];
        for (int i = 0; i <= MAX_EDGE_VAL; i++) {
            graph[i] = new ArrayList();
        }

        for (int[] edge: edges) {
            seen.clear();
            //for each edge from source to target
            //if (!graph[edge[0]].isEmpty() && !graph[edge[1]].isEmpty() &&dfs(graph, edge[0], edge[1])) {
            if   (dfs(graph, edge[0], edge[1])) {
                return edge;
            }
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        throw new AssertionError();
    }
    
    //visit graph, array of nodes, each node has a nei list
    //put not seen node into seen set
    public boolean dfs(ArrayList<Integer>[] graph, int source, int target) {
        if (!seen.contains(source)) {
            seen.add(source);
            if (source == target) return true;
            for (int nei: graph[source]) {
                if (dfs(graph, nei, target)) return true;
            }
        }
        //source seen, return false and exit recur
        return false;
    }
}

