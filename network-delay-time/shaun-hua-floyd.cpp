/*
C++ / Floyd-Warshall, dynamic programming actually
it is general to find shortest distance between any pair of nodes
Time complexity: O(n^3)
Space complexity: O(n^2)
runtime 128ms, faster than 37%, mem less than 85%
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        const int MAX_TIME = 101*100;
        vector<vector<int>> d(N, vector<int>(N, MAX_TIME));
        
        for (auto& time : times)   
            d[time[0] - 1][time[1] - 1] = time[2];
        
        for (int i = 0; i < N; ++i)
            d[i][i] = 0;
        
        for (int k = 0; k < N; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)                    
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        
        int max_time = *max_element(d[K - 1].begin(), d[K - 1].end());        
        return max_time >= MAX_TIME ? - 1 : max_time;
    }
};
