/*
extract braces into vector<vector<char>>
j=0
"{ a, b, c} d { e , f }"
   0  0  0  1   2   2
    ""
dfs(v, nb, cur, s, res)
cur is index from 0 to end in v
s is the candidate growing str
if i == v.size()
  res.push_back(s)
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> expand(string S) {
        vector<vector<char>> vc;
        int j = 0;
        bool brace_open = false; //brace open or not
        unordered_map<char,int> idx;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '{') {
                brace_open = true;
                if (j != 0) j++;
                continue;
            }
            if (S[i] == '}') {
                brace_open = false;
                continue;
            }
            if (S[i] == ',') continue;
            
            if (S[i] >= 'a' && S[i] <= 'z') {
                if (!brace_open) j++;
                idx[S[i]] = j;
                
            }
        }
        
        vc.resize(j);
        for (auto kv: idx) {
            vc[kv.second].push_back(kv.first);
        }
        vector<string> res;
        string s;
        dfs(vc, 0, s, res);
        return res;
    }
private:
    void dfs(vector<vector<char>>& v, int cur, string& s, vector<string>& res) {
        if (cur == v.size()) {
            res.push_back(s);
            return;
        }
        for (char ch: v[cur]) {
            s.push_back(ch);
            dfs(v, cur+1, s, res);
            s.pop_back();
        }
    }
	int main() {
		bool brace_open = false;
		string S = "{a,b,c}d{e,f}";
        unordered_map<char,int> idx;
		int j = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '{') {
                brace_open = true;
                if (j != 0) j++;
                continue;
            }
            if (S[i] == '}') {
                brace_open = false;
                continue;
            }
            if (S[i] == ',') continue;
            
            if (S[i] >= 'a' && S[i] <= 'z') {
                if (!brace_open) j++;
                idx[S[i]] = j;
            }
        }
		for (auto kv: idx) {
			cout << kv.first << " " << kv.second << endl;
		}
		return 0;
	}
};
/*
a d
    
b d
c d
*/
