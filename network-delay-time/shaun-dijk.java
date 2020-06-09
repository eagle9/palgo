/*Runtime: 5 ms, faster than 96.70% of Java online submissions for Network Delay Time.
Memory Usage: 43.7 MB, less than 90.48% of Java online submissions for Network Delay Time.

shaun directly apply of dijkstra algorithm with minHeap
kind of bfs with q, but priority queue, greedily update dist 
classical algorithm to find shortest distance from a single source
check my palgo/doc for dijkstra template

*/
class Solution {
    
    public int networkDelayTime(int[][] times, int N, int K) {
        int [][] edges = new int[N+1][N+1];
        for (int [] row: edges) Arrays.fill(row, -1);
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a,b)-> {
            if (a[0] != b[0]) return a[0]-b[0];
            return a[1] - b[1];
        });
        
        minHeap.offer(new int[]{0,K});
        int [] dist = new int[N+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[K] = 0;
        //row is 0 1 2 tuple
        for (int [] row : times) edges[row[0]][row[1]] = row[2];
        
        while (!minHeap.isEmpty()) {
            int u = minHeap.poll()[1];
            for (int v = 1; v <= N; v++) {
                //the following condition prevents visited vertix being revisited
                if (edges[u][v] != -1 && dist[u] + edges[u][v] < dist[v]) {
                    dist[v] = dist[u] + edges[u][v];
                    minHeap.offer(new int[]{dist[v], v});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            ans = Math.max(ans, dist[i]);
        }
        return ans == Integer.MAX_VALUE? -1: ans;
    }
}


//runtime 100ms, faster than 66%, mem less than 67%
//represent graph with adjacent matrix, but use priority queue, easier to master
/*
typedef pair<int,int> iPair;
class Solution {
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
                    //minHeap.push(make_pair(dist[v], v));
                    minHeap.push({dist[v], v});
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
*/
