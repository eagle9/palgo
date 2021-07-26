class Solution {
    
    class UnionFindSet {
        private int [] parents;
    
        private int [] ranks;

        public UnionFindSet(int n) {
            parents = new int [n + 1];
            ranks = new int [n + 1];

            for (int i = 0; i < parents.length; ++i)
                parents[i] = i;
        }
        //
        boolean union(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) return false;  //union fail, no need

            //no same parent, smaller rank become child
            if (ranks[pu] < ranks[pv]) {
                parents[pu] = pv;
            } else if (ranks[pv] > ranks[pu]) {
                parents[pv] = pu;
            } else { //equal rank
                parents[pu] = pv;
                ranks[pv]++;
            }
 
            return true; //union success
        }
        int find(int id) {        
            if (id != parents[id]) { //not yet top
                parents[id] = find(parents[id]);
            }
            return parents[id];
        }
    }
    
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        UnionFindSet s = new UnionFindSet(n);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (isConnected[i][j] == 1) s.union(i, j);
        
        //find unique root
        Set<Integer> circles = new HashSet<>();
        for (int i = 0; i < n; ++i)
            circles.add(s.find(i));
        
        return circles.size();
    }
}

//hua union find, runtime 24ms, faster than 97%
//direct application of union find, shaun got it

