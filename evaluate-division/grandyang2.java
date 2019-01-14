/*
grandyang graph idea2, runtime  4ms, faster than 38%

*/
class Solution {
    private class Pair {
        String str;
        double val;
        public Pair(String str, double val) {
            this.str = str;
            this.val = val;
        }
    }
    public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
        double [] res = new double[queries.length]; 
        Map<String,Map<String,Double>> g = new HashMap<>();
        Map<String,Double> m2 = null;
        for (int i = 0; i < equations.length; i++) {
            String a = equations[i][0], b = equations[i][1];
            m2 = g.getOrDefault(a, new HashMap<>());
            m2.put(b,values[i]);
            m2.put(a,1.0);
            g.put(a,m2);
            
            m2 = g.getOrDefault(b, new HashMap<>());
            m2.put(a,1.0/values[i]);
            m2.put(b,1.0);
            g.put(b,m2);
        }
        int idx = 0;
        
        for (String [] q : queries) {
            String a = q[0], b = q[1];
            if (!g.containsKey(a) || !g.containsKey(b)) {
                res[idx++] = -1.0;
                continue;
            }
            
            //now both a and b in graph g
            Queue<Pair> que = new LinkedList<>();
            que.offer(new Pair(a, 1.0));
            
            Set<String> visited = new HashSet<>();
            visited.add(a);
            boolean found  = false;
            m2 = null;
            while (!que.isEmpty() && ! found) {
                for (int i = 0; i < que.size(); i++) {
                    Pair p = que.poll();
                    if (p.str.equals(b)) {
                        res[idx++] = p.val;
                        found = true;
                        break;
                    }
                    
                    m2 = g.get(p.str);
                    if (m2 != null) {
                        for (String k: m2.keySet()) {
                            if (visited.contains(k)) continue;
                            visited.add(k);
                            double v = m2.get(k);
                            v *= p.val;
                            que.offer(new Pair(k,v));
                        }
                    }
                    
                }
            }
            if (!found) res[idx++] = -1.0;
        }
        return res;
    }
}


/*
//grandyang graph idea, runtime 0ms, faster than 100%

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res;
        unordered_map<string, unordered_map<string, double>> g;
        for (int i = 0; i < equations.size(); ++i) {
            g[equations[i].first].emplace(equations[i].second, values[i]);
            g[equations[i].first].emplace(equations[i].first, 1.0);
            g[equations[i].second].emplace(equations[i].first, 1.0 / values[i]);
            g[equations[i].second].emplace(equations[i].second, 1.0);
        }
        for (auto query : queries) {
            if (!g.count(query.first) || !g.count(query.second)) {
                res.push_back(-1.0);
                continue;
            }
            queue<pair<string, double>> q;
            unordered_set<string> visited{query.first};
            bool found = false;
            q.push({query.first, 1.0});
            while (!q.empty() && !found) {
                for (int i = q.size(); i > 0; --i) {
                    auto t = q.front(); q.pop();
                    if (t.first == query.second) {
                        found = true;
                        res.push_back(t.second);
                        break;
                    }
                    for (auto a : g[t.first]) {
                        if (visited.count(a.first)) continue;
                        visited.insert(a.first);
                        a.second *= t.second;
                        q.push(a);
                    }
                }
            }
            if (!found) res.push_back(-1.0);
        }
        return res;
    }
};
*/
