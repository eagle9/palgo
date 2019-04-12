/*jz cpp, shaun read and modified to linhuchong idea
Runtime: 16 ms, faster than 99.78% of C++ online submissions for Graph Valid Tree.
Memory Usage: 10.9 MB, less than 62.22% of C++ online submissions for Graph Valid Tree.
*/
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        
        //check 1, number of edges == n-1 ????
        if (edges.size() != n -1) return false;
        
        //vector or umap int to uset<int>
        vector<unordered_set<int>> g(n, unordered_set<int>()); //nodes are number from 0 to n-1, using vector is simpler than unordered_map
        for (auto a : edges) {
            g[a.first].insert(a.second);
            g[a.second].insert(a.first);
        }
        
        unordered_set<int> v;
        queue<int> q;
        q.push(0);
        v.insert(0);
        
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (auto nb : g[node]) {
                //if (v.find(a) != v.end()) return false; //cycle, continue is okay, return is better
                if (v.find(nb) != v.end()) continue; //visisted
                v.insert(nb);
                q.push(nb);
                //g[nb].erase(t);
            }
        }
        return v.size() == n;
    }
};
