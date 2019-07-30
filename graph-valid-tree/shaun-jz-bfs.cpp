/*shaun coded from jz linhuchong idea, fixed a number of typos, first sub wrong answer
4
[[0,1],[0,2],[1,2]]

//add some code, accepted, then checked jz code, use graph bfs template, cleaner code
Runtime: 16 ms, faster than 99.78% of C++ online submissions for Graph Valid Tree.
Memory Usage: 11.2 MB, less than 60.00% of C++ online submissions for Graph Valid Tree.
*/
typedef unordered_map<int,unordered_set<int>> graph;
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        
        //check 1: number of edges == n-1????
        if (edges.size() != n-1) return false;
        
        //check 2: from one node, can we visit all other nodes, visit count == n?
        //init graph
        graph g = init_graph(n, edges);
        queue<int> q;
        q.push(0);
        unordered_set<int> visited;
        visited.insert(0);
        
        int count = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            
            count++;
            
            for (int nb: g[node]) {
                if (visited.count(nb)) continue;
                visited.insert(nb);
                q.push(nb);
            }
        }
        return count == n;
    }
private:
    //for each vertex, store its neighbors in a set
    
     graph init_graph(int n, vector<pair<int, int>>& edges) {
        graph g;
        for (int i = 0; i <= n-1; ++i) {
            //unordered_set<int> s;
            g[i] = unordered_set<int>();
        }
        for (auto p: edges) {
            g[p.first].insert(p.second);
            g[p.second].insert(p.first);
        }
        return g;
    }
};
