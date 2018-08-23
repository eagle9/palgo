//jz c++ bfs version,Your submission beats 30.80% Submissions!
//Your submission beats 44.60% Submissions!
#include <vector>
#include <unordered_set>
#include <queue>
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n, unordered_set<int>());

        for (auto a : edges) {
            g[a[0]].insert(a[1]);
            g[a[1]].insert(a[0]);
        }
        unordered_set<int> v; //visited
        queue<int> q;
        q.push(0);
        v.insert(0);
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (auto a : g[t]) {
                if (v.find(a) != v.end()) return false;
                v.insert(a);
                q.push(a);
                g[a].erase(t);
            }
        }
        return v.size() == n;
    }
};
