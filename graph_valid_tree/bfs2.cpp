//jz c++ bfs version,Your submission beats 30.80% Submissions!
//Your submission beats 91.80% Submissions!


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 0) return false;
        if (edges.size() != n-1) return false;
        vector<unordered_set<int>> g(n, unordered_set<int>());

        for (auto edge : edges) {
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        }
        unordered_set<int> v; //visited
        queue<int> q;
        q.push(0);
        v.insert(0);
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (auto neighbor : g[node]) {
                if (v.find(neighbor) != v.end()) continue;//visited, return false;
                v.insert(neighbor);
                q.push(neighbor);
                //g[a].erase(t);
            }
        }
        return v.size() == n;
    }
};
