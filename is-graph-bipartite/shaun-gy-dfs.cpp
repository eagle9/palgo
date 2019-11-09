/*gy dfs idea, similar to my init try, but i was not clear about the 2 color trick
// also not sure about helper's return value, use example to figure out the details
//runtime 24ms, faster than 84%, mem less than 97%
color = 0, not yet colored, two colors: 1 and -1

time O(N+E), space O(N)

*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n);//stores the color of each node, init color is all 0
        for (int i = 0; i < n; ++i) {
            if (colors[i] == 0 && !dfs(graph, 1, i, colors)) {
                return false;
            }
        }
        return true;
    }
    //color graph nodes, from node cur:color, color neighbors with flipped color, if already colored, must be expected color, otherwise, no good, return false, good return true
    bool dfs(vector<vector<int>>& graph, int color, int cur, vector<int>& colors) {
        //cur already colored and expected color, works, return true
        if (colors[cur] != 0) return colors[cur] == color;
        
        //not yet colored, node cur colored with 'color'
        colors[cur] = color;
        for (int i : graph[cur]) {
            //try to color node cur's neighbors with flipped color, not work, return false
            if (!dfs(graph, -1 * color, i, colors)) {
                return false;
            }
        }
        //at this point, can color node cur's neighbors with flipped color, good, return true
        return true;
    }
};
