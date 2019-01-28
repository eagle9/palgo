// Author: Huahua, dfs with backtracking
// Runtime: 8 ms, faster than 80%
class Solution {
public:
    string crackSafe(int n, int k) {
        const int total_len = pow(k, n) + n - 1;
        string ans(n, '0');
        unordered_set<string> visited{ans};
        if (dfs(ans, total_len, n, k, visited))
            return ans;
        return "";
    }
private:
    bool dfs(string& ans, const int total_len, const int n, const int k, unordered_set<string>& visited) {
        if (ans.length() == total_len)
            return true;
        
        string node = ans.substr(ans.length() - n + 1, n - 1);
        for (char c = '0'; c < '0' + k; ++c) {
            node.push_back(c);
            if (!visited.count(node)) {
                ans.push_back(c);
                visited.insert(node);
                if (dfs(ans, total_len, n, k, visited)) return true;
                //else not find it, backtrack
                visited.erase(node); //back track 1
                ans.pop_back(); //backtrack 2
            }
            node.pop_back(); //backtrack 3
        }
        
        return false;
    }
};
