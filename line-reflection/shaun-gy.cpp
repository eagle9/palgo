//gy idea with hint
//time O(n), space O(n)
//runtime 28ms, faster than 96%, mem less than 100%
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int, set<int>> m;
        int maxx = INT_MIN, minx = INT_MAX;
        for (auto a : points) {
            maxx = max(maxx, a[0]);
            minx = min(minx, a[0]);
            m[a[0]].insert(a[1]);
        }
        double mid = (double)(maxx + minx) / 2;
        for (auto a : points) {
            // t .    mid       a[0],a[1]
            // for x = a[0], find a match to a[1]?  both t and a[1] in a set for key=a[0]
            int t = 2 * mid - a[0];
            if (!m.count(t) || !m[t].count(a[1])) {
                return false;
            }
        }
        return true;
    }
}; 
