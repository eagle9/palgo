//shaun bfs upon gy hint
//cutting: assign nodes to two sets A/B, if uv is an edge, u v can not be the same set/color
//  bfs, try to color each connected component,  once found uv colored the same, return false
//  after all, return true
//runtime 24ms, faster than 84%, mem less than 11%
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); //number of nodes
        //undirected graph, connected or not, we don't know
        vector<int> color(n); //set membership of each node, 0 for undefined, 1 for A, 2 for B
        for (int i = 0; i < n; ++i) {
            queue<int> q;
            q.push(i);
            if (color[i] == 0) color[i] = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                //for each neighbor of node
                for (int v: graph[u]) {
                    if (color[v] ==0) { //not yet colored
                        color[v] = flip(color[u]);
                        q.push(v);
                    }else {
						//already colored, same color, violation, return false
                        if (color[v] == color[u]) return false;
                        else continue;
                    }
                }
            }
        }
        //no uv same color found
        return true;
    }
private:
    int flip(int color) {
        if (color == 1) return 2;
        if (color == 2) return 1;
        return color;
    }
};
