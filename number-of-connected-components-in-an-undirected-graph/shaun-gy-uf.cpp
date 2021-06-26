//shaun gy uf
//runtime 20ms, faster than 80%, mem less than 60%
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = n;
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        for (auto a : edges) {
            int p0 = find(parent, a[0]), p1 = find(parent, a[1]);
            if (p0 != p1) {
                --res; //each union decrease by 1, makes sense
                parent[p1] = p0; //simply union without considering rank
            }
        }
        return res;
    }
private:
    int find(vector<int>& parent, int i) {
        while (i != parent[i]) i = parent[i];
        return i;
    }
};
