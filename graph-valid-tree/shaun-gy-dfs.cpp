// shaun and gy DFS to check cycle and can visit all n nodes? 
//runtime 20ms, faster than 68%, mem less than 11%
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        vector<bool> visited(n, false);
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        //no cycle found
        if (!dfs(g, visited, 0, -1)) return false;
        
        //if any node is not visited, not all connected, return false
        for (auto a : visited) {
            if (a == false) return false;
        }
        return true;
    }
    bool dfs(vector<vector<int>> &g, vector<bool> &visited, int cur, int pre) {
        if (visited[cur]) return false; //cycle found
        visited[cur] = true;
        for (const auto& v : g[cur]) {
            if (v != pre) { //don't go back
                if (!dfs(g, visited, v, cur)) return false;
            }
        }
        //no cycle found
        return true;
    }
};
