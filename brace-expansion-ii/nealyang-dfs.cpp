//https://leetcode.com/problems/brace-expansion-ii/discuss/422913/c%2B%2B-slow-but-easy-understand-dfs
//runtime 28ms, faster than 6%, mem less than 100%
class Solution {
private:
    void dfs(string& expression, int i, int& j, string cur, vector<string>& res) {
        if (i == expression.length() || expression[i] == ',' || expression[i] == '}') {
            j = i;
            res.push_back(cur);
            return;
        }
        
        vector<string> temp;
        if (expression[i] == '{') {
            temp = unionChunk(expression, i);
        } else {
            temp.push_back(string(1, expression[i]));
        }
        
        for (auto val : temp) {
            dfs(expression, i + 1, j, cur + val, res);
        }
    }
    
    vector<string> unionChunk(string& expression, int& i) {
        unordered_set<string> ans;
        
        while(expression[i] != '}') {
            i = i + 1;
            vector<string> res;
            dfs(expression, i, i, "", res);
            for (auto m : res)
                ans.insert(m);
        }
        
        vector<string> ansV;
        ansV.insert(ansV.end(), ans.begin(), ans.end());
        return ansV;
    }
    
public:
    vector<string> braceExpansionII(string expression) {
        vector<string> res;
        int j = 0;
        dfs(expression, 0, j, "", res);
        sort(res.begin(), res.end());
        return res;
    }
};

