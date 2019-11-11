//shaun idea to apply uf template, init parent& rank on the fly
//grandyang hint with init and uf on the fly
//uf template fixed two bugs
//runtime 168ms, faster than 40%, mem less than 5%
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        int cnt = 0;
        parent.resize(m * n, -1);
        rank.resize(m*n);
        
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        
        //add land step by step 
        for (auto v : positions) {
            int id = n * v[0] + v[1];
            
            if (parent[id] == -1) {
                parent[id] = id;
                ++cnt;
            }
            for (auto dir : dirs) {
                int x = v[0] + dir[0], y = v[1] + dir[1], cur_id = n * x + y;
                if (x < 0 || x >= m || y < 0 || y >= n || parent[cur_id] == -1) continue;
                int p = find(cur_id), q = find(id);
                if (Union(p,q)) cnt--;
            }
            res.push_back(cnt);
        }
        return res;
    }
private:
    vector<int> parent, rank;
    int find(int u) {
        while (u != parent[u]) u = parent[u];
        //now u == parent[u]
        return u;
    }
    bool Union(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        parent[pu] = pv;
        return true;
    }
    int find1(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]); //bug 2 =find(u) ---> find(parent[u])
        }
        return parent[u];
    }
    bool Union1(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (rank[pu] <= rank[pv]) { //bug 1, < ---> <=
            parent[pu] = pv;
            rank[pv]++;
        }else if (rank[pv] < rank[pu]){
            parent[pv] = pu;
            rank[pu]++;
            
        }
        return true;
    }
};
