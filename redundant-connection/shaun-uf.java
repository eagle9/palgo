class Solution {
    int N;
    int [] parent;
    int [] rank;
    //find parent of u
    int Find(int u) {
        if (parent[u] != u) {
            parent[u] = Find(parent[u]);
        }
        return parent[u];
    };
    public int[] findRedundantConnection(int[][] edges) {
        int [] res = new int[2];
        
        N = edges.length;
        parent = new int[N+1];
        rank = new int[N+1];
        for (int i = 1; i <= N; ++i) {
            parent[i] = i;
            //rank[i] = 0; //in java not needed
        }
        
        for (int [] edge: edges) {
            int u = edge[0], v = edge[1];
            if (Find(u) == Find(v)) {
                res = new int [] {u,v};
                break;
            }
            Union(u,v);
        }
        return res;
    }
    boolean Union(int u, int v) {
        int parent1 = Find(u), parent2 = Find(v);
        if (parent1 == parent2) return false;
        
        if (rank[parent1] < rank[parent2]) {
            parent[parent1] = parent2;
        }else if (rank[parent2] < rank[parent1]) {
            parent[parent2] = parent1;
        
        }else { // rank ==
            parent[parent1] = parent2;
            rank[v]++;
        }
        return true;
            
    }
}

//shaun own try with vague memory of union find
//bug 1 --- use lower case union to name union function,union is c++ keyword
//bug 2 --- Union function better return bool, my init try void, okay
//bug 3 --- vector index from 1 to N, vector size should be N+1
//bug 4 --- for i = 1; i <N; ++i,  ----> i <= N
//bug 5 --- didn't get Union function right, get parents for u and v, first, then work on their parents
//accepted after fixing all 5 bugs, runtime 8ms, faster than 93%, mem less than 54%


