//shaun jz bfs
//cutting: number of edges == n-1?  --- with n-1 edges
// bfs with visited set and queue, visited.size() == n?  --- all n nodes connected

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;
        
        //graph node to its neighbors (set)
        vector<unordered_set<int>> g(n, unordered_set<int>());
        //unordered_set<int> visited{{0}};
        //queue<int> q{{0}};
        unordered_set<int> visited;visited.insert(0);
        queue<int> q; q.push(0);
        
        //undirected graph
        for (const auto& e : edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const auto& v : g[u]) {
                if (visited.count(v)) continue;
                visited.insert(v);
                q.push(v);
                
            }
        }
        return visited.size() == n;
    }
};
