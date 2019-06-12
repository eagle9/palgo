//bug 1 Line 933: Char 34: runtime error: reference binding to null pointer of type 'value_type' (stl_vector.h) ---->  parent = vector<int>(N)

//bug 2 class DSU definition must be before class Solution

//shaun own idea with uf, accepted after fixing 2 bugs
//accepted first sub, runtime 20ms, faster than 98%, mem less than 59%

class DSU {
private:    
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(int N) {
        parent = vector<int>(N);
        rank = vector<int>(N);
        for (int i = 0; i < N; ++i) {
            parent[i] = i;
           
        }
    }
    int Find(int u) {
        if (u != parent[u]) parent[u] = Find(parent[u]);
        return parent[u];
    }
    
    bool Union(int u, int v) {
        int pu = Find(u), pv = Find(v);
        if (pu == pv) return false;
        //code later begin
        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pv] < rank[pu]) parent[pv] = pu;
        else {
            parent[pu] = pv;
            rank[pv]++;
        } //code later end
        
        //parent[pu] = pv;  //no rank first, works
        return true;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        DSU dsu(N);
        for (int i = 0; i < N; ++i ) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                if (M[i][j]) dsu.Union(i,j);
            }
        }
        unordered_set<int> ans;
        for (int i = 0; i < N; ++i) {
            ans.insert(dsu.Find(i));
        }
        return ans.size();
    }
};

