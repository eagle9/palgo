//grandyang dijkstra algo template with queue bfs level traversal
//runtime 84ms, faster than 96%, mem less than 50%
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int res = 0;
        //adjacent matrix, N+1 x N+1, connection between all node lables 1 to N
        //when no connection, the value is set to -1
        vector<vector<int>> edges(N+1, vector<int>(N+1, -1));
        queue<int> q{{K}};
        //distance from source K to node label 1 to N, initially INT_MAX
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (auto e : times) edges[e[0]][e[1]] = e[2];
        
        
        while (!q.empty()) {
            unordered_set<int> visited; //why here???
            for (int i = q.size(); i > 0; --i) {
                int u = q.front(); q.pop();
                for (int v = 1; v <= N; ++v) {
                    //check u v connection 
                    if (edges[u][v] != -1 && dist[u] + edges[u][v] < dist[v]) {
                        if (!visited.count(v)) {
                            visited.insert(v);
                            q.push(v);
                        }
                        dist[v] = dist[u] + edges[u][v];
                    }
                }
            }
        }
        //now dist stores distance from K to i(1--N)
        for (int i = 1; i <= N; ++i) {
            res = max(res, dist[i]);
        }
        //according to problem statement, not reach all will be -1
        return res == INT_MAX ? -1 : res;
    }
};

//runtime 100ms, faster than 66%, mem less than 67%
//represent graph with adjacent matrix, but use priority queue, easier to master
typedef pair<int,int> iPair;
class Solution2 {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        vector<vector<int>> edges(N+1, vector<int>(N+1, -1));
        priority_queue<iPair,vector<iPair>,greater<iPair>> minHeap;
        minHeap.push(make_pair(0, K));
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (auto e : times) edges[e[0]][e[1]] = e[2];
        
        while (!minHeap.empty()) {
            int u = minHeap.top().second; minHeap.pop();
            //update all u's neighbors when we can
            for (int v = 1; v <= N; ++v) {
                if (edges[u][v] != -1 && dist[u] + edges[u][v] < dist[v]) {
                    dist[v] = dist[u] + edges[u][v];
                    minHeap.push(make_pair(dist[v], v));
                }
            }
        
        }
        int res = 0;
        for (int i = 1; i <= N; ++i) {
            res = max(res, dist[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};

/*
input:
[[1,2,1],[2,3,7],[1,3,4],[2,1,2]]
4,1
        
output: 4
expected: -1, ---- really? 
i see! this problem asks that all nodes from 1 and N can be reached. 
 node 4 is not in the graph, so node 4 can not be reached. 
 you just have to assume all nodes from 1 to N
 runtime 108ms, faster than 61%, mem less than 32%
 
 int this solution, the graph is represented with map<int, vector<pair<int,int>>>
 that stores each node's neighbors
*/

typedef pair<int,int> iPair;
typedef unordered_map<int,vector<pair<int,int>>> Graph;
class Solution3 {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        Graph graph;
        unordered_set<int> nodes;
        unordered_map<int,int> dist;
        for (auto e : times) {
            int u = e[0], v = e[1], w = e[2];
            //nodes.insert(u);
            //nodes.insert(v);
            graph[u].push_back(make_pair(v,w));
        }
        //for (const auto& u: nodes) dist[u] = INT_MAX;
        for (int u = 1; u <= N; ++u) dist[u] = INT_MAX;
        dist[K] = 0;
        
        priority_queue<iPair,vector<iPair>,greater<iPair>> minHeap;
        minHeap.push(make_pair(0, K));
        
        while (!minHeap.empty()) {
            int u = minHeap.top().second; minHeap.pop();
            for (const auto& temp: graph[u]) {
                int v = temp.first, w = temp.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    minHeap.push(make_pair(dist[v], v));
                }
            }
        
        }
        int res = 0;
        for (const auto& temp: dist) res = max(res, temp.second);
        return res == INT_MAX ? -1 : res;
    }
};
