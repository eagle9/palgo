// Time Complexity: O(n^2)
// Runtime: 32 ms, faster than 16.27% of C++ online submissions for Redundant Connection.
//huahua dfs to find path in a graph
//growing graph and find answer on the fly
//shaun deep read and understood, better than shaun's first idea
//my first idea is to use dfs to find cycle, then go through the cycle to find the last edge by edge list, kind of hard to implement
//shaun also come up uf idea, and found it is very clean
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //grow the graph, node to its neighbor list
        unordered_map<int, vector<int>> graph;
        //iterate edge list to find redundant edge
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            //for each u,v, do dfs to find path, with a fresh visit set
            unordered_set<int> visited;
            if (hasPath(u, v, graph, visited)) //if path, then redundant
                return edge;
            
            //no path, add u&v won't create cycle, add to graph
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        //at this point, no redundant found
        return {};
    }
private:
    bool hasPath(int curr, 
                 int goal, 
                 const unordered_map<int, vector<int>>& graph, 
                 unordered_set<int>& visited) {
        //dfs template 1, exit condition
        if ( curr == goal) return true;
        
        //dfs template 2, visit add curr
        visited.insert(curr);
        //growing graph, curr or goal might not in graph yet
        if (!graph.count(curr) || !graph.count(goal)) return false;
        //dfs template 3, for each neighbor, recur
        for (int next : graph.at(curr)) {
            if (visited.count(next)) continue; //skip visited
            if (hasPath(next, goal, graph, visited)) return true;
            //else try other neighbor
        }
        //neighbor leads to goal
        return false;
    }
};
