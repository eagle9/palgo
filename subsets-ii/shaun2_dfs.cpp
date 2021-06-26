//shaun 2nd first try, accepted first sub
//runtime 8ms, faster than 100%, mem less than 18%
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int i: nums) {
        	m[i]++;
        }
        vector<int> a(m.size());
        int i = 0;
        for (auto p: m) a[i++] = p.first;

        vector<int> cur;
    	vector<vector<int>> res;
        dfs(a, m, 0, cur, res);
        return res;

    }
private:
	void dfs(vector<int>& a, unordered_map<int,int>& m, int i, vector<int>& cur, vector<vector<int>>& res) {

		if (i == a.size()) {
			res.push_back(cur);
			return;
		}
		//take a[i] 0 to m[a[i]] times
		int count = m[a[i]];
		for (int j = 0; j <= count; ++j) {
			for (int k = 0; k < j; ++k) cur.push_back(a[i]);
			dfs(a, m, i+1, cur, res);
			for (int k = 0; k < j; ++k) cur.pop_back();
		}

	}
};
