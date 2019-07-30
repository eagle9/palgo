/*
hua C++ / Bellman-Ford algorithm template 
Time complexity: O(ne)
Space complexity: O(n)
shaun code from memory, accepted after 2 bug fixes
1) distv > distu + w signed int overflow
2) missing the for i = 1 to N loop, not quite understand, just remember it
runtime 116ms, faster than 50%, mem less than 99%
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N, INT_MAX);
        dist[K-1] = 0;
        //why loop from 1 to N-1? 
        for (int i = 1; i < N; ++i) {
            //for (auto edge: times) { //slower, use ref & faster
            for (const auto& edge: times) {
                int u = edge[0]-1, v = edge[1]-1, w = edge[2];
                if (dist[v] - w > dist[u]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        int res = *max_element(dist.begin(), dist.end());
        return res == INT_MAX? -1: res;
    }
};
//hua's original code
class Solution2 {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        constexpr int MAX_TIME = 101 * 100;
        vector<int> dist(N, MAX_TIME);
        dist[K - 1] = 0;
        for (int i = 1; i < N; ++i)
            for (const auto& time : times) {
                int u = time[0] - 1, v = time[1] - 1, w = time[2];
                dist[v] = min(dist[v], dist[u] + w);
            }
        int max_dist = *max_element(dist.begin(), dist.end());
        return max_dist == MAX_TIME ? -1 : max_dist;
    }
};
