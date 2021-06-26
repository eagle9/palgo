//shaun code from jz dfs backtrack combination idea and his java code
//first sub wrong answer, then many subs still wrong answer
//finally spotted the difference, dfs(s, i+1) --> dfs(s, right+1)
//runtime 72ms, faster than 30%, mem less than 47%
class Solution {
public:
    vector<vector<string>> partition(string s) {
 		vector<vector<string>> res;
        if (s.empty()) return res;
        vector<string> cur;
        dfs(s,0,cur,res);
        return res;
	}
private:
    void dfs(const string s, int i, vector<string>& cur, vector<vector<string>>& res) {
        if (i == s.size()) {
            res.push_back(cur);
            return;
        }
        for (int right = i; right < s.size(); ++right) {
            int len = right - i + 1;
            string sub = s.substr(i, len);
            if (is_valid(sub)) {
                cur.push_back(sub);
                //0 - right into cur, already, now investiage right+1 to end
                dfs(s,right+1,cur,res);
                cur.pop_back();
            }
        }
    }
	bool is_valid(const string s) {
		int n = s.size();
		if (n == 0 || n == 1) return true;
		int left = 0, right = s.size()-1;
		while (left < right) {
			if (s[left] != s[right]) return false;
			left++;
			right--;
		}
		return true;
	}
};
/*
idea
break s into 0 to i,  i+1 to len-1
dfs(string s, )
if 0 to i is palindrome, then recur
*/
