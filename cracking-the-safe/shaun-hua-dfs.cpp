/*
hua dfs idea, overlapping passwords n-1 chars
shaun got the idea and coded from memory of the idea
runtime 12ms, faster than 77%, mem less than 50%

*/
class Solution {
public:
    string crackSafe(int n, int k) {
        string res = string(n, '0');
        unordered_set<string> visited{{res}};
        int total_size = pow(k,n);   //k^n passwords, first len n, all other passwords contribute 1 char each
        dfs(n, k, total_size, visited, res);
        return res;
    }
    bool dfs(int n, int k, int total, unordered_set<string>& visited, string& res) {
        if (visited.size() == total) return true;
        //previous password last n-1 chars of res
        string pre = res.substr(res.size() - n + 1, n - 1);
        for (char c = '0'; c < '0'+k; ++c) {
            string cur = pre;
            cur.push_back(c);
            if (visited.count(cur)) continue;
            //now cur not yet visited
            visited.insert(cur);
            res.push_back(c);
            if (dfs(n, k, total, visited, res)) return true;
            visited.erase(cur);
            res.pop_back();
            //cur.pop_back();
            
        }
        return false;
    }
};

