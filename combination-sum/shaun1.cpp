//shaun'w own recursion and backtracking idea, runtime 20ms, faster than 65%, memory less than 32%
//accepted second sub,  fixed just 1 line --- the for loop exit condition < target to <= target
//march 25 2019
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> cur;
        vector<vector<int>> res;
        helper(candidates, target, 0, 0, cur, res);
        return res;
    }
private:
	void helper(vi& candidates, int target, int i, int curSum, vi& cur, vvi& res ) {
		if (i == candidates.size()) {
			if (curSum == target) res.push_back(cur);
			return;
		}
		//try use ci  0 or inf times, fixed before first sub, from j= 0 rather than j=1
		for (int j = 0; curSum + j*candidates[i] <= target; ++j) { 
			for (int k = 0; k < j; ++k) cur.push_back(candidates[i]);
			curSum += j*candidates[i];
			helper(candidates, target, i+1, curSum, cur, res);
			for (int k = 0; k < j; ++k) cur.pop_back();
			curSum -= j*candidates[i];
		}
	}
};
