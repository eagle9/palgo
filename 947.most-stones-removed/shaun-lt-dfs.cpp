//shaun with lt dfs idea
//to understand better
//runtime 120ms, faster than 25%, mem less than 5%
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int N = stones.size();

        // graph[i][0] = the length of the 'list' graph[i][1:]
        vector<vector<int>> graph(N,vector<int>(N));
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i][++graph[i][0]] = j;
                    graph[j][++graph[j][0]] = i;
                }

        int ans = 0;
        vector<bool> seen(N);
        for (int i = 0; i < N; ++i) {
            if (seen[i])  continue;
            
            //dfs from i
            stack<int> stack;
            stack.push(i);
            seen[i] = true;
            ans--; //keep the first node in each component
            while (!stack.empty()) {
                int node = stack.top(); stack.pop();
                ans++;
                for (int k = 1; k <= graph[node][0]; ++k) {
                    int nei = graph[node][k];
                    if (!seen[nei]) {
                        stack.push(nei);
                        seen[nei] = true;
                    }
                }
            }
        }

        return ans;
    }
};
