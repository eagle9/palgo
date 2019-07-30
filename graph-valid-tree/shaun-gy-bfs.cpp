//grandyang bfs,
//cutting: 1) tree, number of edges == number of nodes -1
// bfs traverse the graph, use a visited set, bfs expand, do not go back, if meet a node that is already visited, return false(cycle found), u = q.front(), q.pop(), for u's neigbhor v, is not visited, q.push(v), visited.insert(v), remember erase v-u edge to prevent going back from v to u, make sense right?!
//the bfs will visit all n nodes if valid tree

//runtime 20ms, faster than 68%, mem less than 8%
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
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
                if (visited.count(v)) return false; //cycle found
                visited.insert(v);
                q.push(v);
                g[v].erase(u); //why this line? do not go back, i see, this is very important
            }
        }
        return visited.size() == n;
    }
};


