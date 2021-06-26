/*
grandyang idea1, runtime 3ms, faster than 81%
using map, set, recursion, simple idea
experience of using two key map
第四次编程比赛的压轴题，感觉还是挺有难度的，个人感觉难度应该设为hard比较合理。这道题已知条件中给了一些除法等式，然后给了另外一些除法等式，问我们能不能根据已知条件求出结果，不能求出来的用-1表示。问题本身是很简单的数学问题，但是写代码来自动实现就需要我们用正确的数据结构和算法，通过观察题目中的例子，我们可以看出如果需要分析的除法式的除数和被除数如果其中任意一个没有在已知条件中出现过，那么返回结果-1，所以我们在分析已知条件的时候，可以使用set来记录所有出现过的字符串，然后我们在分析其他除法式的时候，可以使用递归来做。通过分析得出，不能直接由已知条件得到的情况主要有下面三种：

1) 已知: a / b = 2, b / c = 3， 求 a / c
2) 已知: a / c = 2, b / c = 3， 求 a / b
3) 已知: a / b = 2, a / c = 3， 求 b / c

虽然有三种情况，但其实后两种情况都可以转换为第一种情况，对于每个已知条件，我们将其翻转一下也存起来，那么对于对于上面美中情况，就有四个已知条件了：

1) 已知: a / b = 2，b / a = 1/2，b / c = 3，c / b = 1/3，求 a / c
2) 已知: a / c = 2，c / a = 1/2，b / c = 3，c / b = 1/3，求 a / b
3) 已知: a / b = 2，b / a = 1/2，a / c = 3，c / a = 1/3，求 b / c

我们发现，第二种和第三种情况也能转化为第一种情况，只需将上面加粗的两个条件相乘即可。对于每一个需要解析的表达式，我们需要一个HashSet来记录已经访问过的表达式，然后对其调用递归函数。在递归函数中，我们在HashMap中快速查找该表达式，如果跟某一个已知表达式相等，直接返回结果。如果没有的话，那么就需要间接寻找了，我们在HashMap中遍历跟解析式中分子相同的已知条件，跳过之前已经遍历过的，否则就加入visited数组，然后再对其调用递归函数，如果返回值是正数，则乘以当前已知条件的值返回，就类似上面的情况一，相乘以后b就消掉了。如果已知找不到解，最后就返回-1
*/
class Solution {
    public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
        double [] res = new double [queries.length];
        for (int i = 0; i < equations.length; i++) {
            String a = equations[i][0], b = equations[i][1];
            
            Map<String,Double> m2 = m.getOrDefault(a, new HashMap<>());
            m2.put(b,values[i]);
            m.put(a,m2);
            
            m2 = m.getOrDefault(b,new HashMap<>());
            m2.put(a,1/values[i]);
            m.put(b,m2);
        }
        int i = 0;
        for (String [] q: queries) {
            Set<String> visited = new HashSet<>();
            double t = helper(q[0],q[1],visited);
            res[i++] = t > 0? t: -1;
            
        }
        return res;
    }
    private double helper(String up, String down, Set<String> visited) {
        Map<String,Double> m2 = m.get(up);
        if (m2 != null) {
            if (m2.containsKey(down)) return m2.get(down);
            for (String k: m2.keySet()) {
                if (visited.contains(k)) continue;
                visited.add(k);
                double t = helper(k,down,visited);
                if (t >0.0) return t*m2.get(k);
            }
        }
        return -1.0;
    }
    
    private Map<String, Map<String,Double>> m = new HashMap<>();
}


/*
//grandyang idea1, runtime 0ms, faster than 100%


class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res;
        for (int i = 0; i < equations.size(); ++i) {
            m[equations[i].first][equations[i].second] = values[i];
            m[equations[i].second][equations[i].first] = 1.0 / values[i];
        }
        for (auto query : queries) {
            unordered_set<string> visited;
            double t = helper(query.first, query.second, visited);
            res.push_back((t > 0.0) ? t : -1);
        }
        return res;
    }
    double helper(string up, string down, unordered_set<string>& visited) {
        if (m[up].count(down)) return m[up][down];
        for (auto a : m[up]) {
            if (visited.count(a.first)) continue;
            visited.insert(a.first);
            double t = helper(a.first, down, visited);
            if (t > 0.0) return t * a.second;
        }
        return -1.0;
    }

private:
    unordered_map<string, unordered_map<string, double>> m;
};
*/
