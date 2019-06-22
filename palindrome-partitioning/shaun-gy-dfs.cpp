//grandyang dfs, shaun see is as typical cursor building candidate type recursion
//easy to understand
//why backtracking needed?  sub push_back to cur, next might not find palindromic sub
//runtime 44ms, faster than 52%, mem less than 42%
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        dfs(s, 0, out, res);
        return res;
    }
    //cur -- current strings in the partition candidate
    void dfs(string& s, int start, vector<string>& cur, vector<vector<string>>& res) {
        if (start == s.size()) { //base case recur exit
            res.push_back(cur); return; 
        } 
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                cur.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, cur, res);
                cur.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            ++start; --end;
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
