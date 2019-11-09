//shaun gy dfs
//runtime 24ms, faster than 58%, mem less than 20%
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = 0;
        vector<vector<int> > g(n); //for each node, g[node] is a vector of its neighbors
        vector<bool> v(n, false); //v[node] visited or not
        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        //connected component all its node will be marked visited during a dfs call
        for (int i = 0; i < n; ++i) {
            if (!v[i]) {
                ++res;
                dfs(g, v, i);
            }
        }
        return res;
    }
private:
    //dfs traverse graph g (neighbors for each node)
    void dfs(vector<vector<int>>& g, vector<bool>& v, int i) {
        if (v[i]) return; 
        v[i] = true;
        for (int nei: g[i]) {
            if (!v[nei]) dfs(g,v,nei);
        }
    }
};
