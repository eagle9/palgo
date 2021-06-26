//shaun's first try, accepted after s.size == 0 case push_back({})
//runtime 216ms, faster than 5%, mem less than 5%
class Solution {
public:
    vector<vector<string>> partition(string s) {
 		vector<vector<string>> res;
		/*if (s.size() == 0) {
            res.push_back({});
            return res;
        };*/
		if (s.size() == 1) {
			res.push_back({s});
			return res;
		}
		int n = s.size();
		for (int i = 1; i <= n; ++i) {
			string a = s.substr(0,i), b = (i == n)? "": s.substr(i,n-i);

			if (is_valid(a) )  {
                if (b.size()) {
                    vector<vector<string>> resb = partition(b);
                    for (auto vs: resb) {
                        vs.insert(vs.begin(), a);
                        res.push_back(vs);
                    }
                }else {
                    res.push_back({a});
                }
			}
		}
        return res;
	}
	bool is_valid(string s) {
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
