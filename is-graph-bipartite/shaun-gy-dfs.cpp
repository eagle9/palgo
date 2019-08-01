//grandyang union find idea
//cutting: union find, i  --- 0,1, ...  0-1 same parent, can be same as i's parent
//runtime 24ms, faster than 84%, mem less than 99%
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        parent = vector<int>(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        
        for (int i = 0; i < n; ++i) {
            if (graph[i].empty()) continue;
            int x = find(i), y = find(graph[i][0]);
            if (x == y) return false;
            
            for (int j = 1; j < graph[i].size(); ++j) {
                int v = graph[i][j];
                int pv = find(v);
                if (pv == x) return false;
                //union
                parent[pv] = y;
            }
        }
        return true;
    }
private:
    vector<int> parent;
    int find(int i) {
        while (i != parent[i]) i = parent[i];
        return i;
    }
};
