//shaun's own idea, runtime 12ms, faster than 85%, memory less than 25%
//accepted after adding i++ after nums[i] = p.first; count[i] = p.second;
// my thinking is similar to combination sum 1, where you can use a number 0 or more times
// here in 2, can only take a number as its copies allow
//so i did the processing get a unique number array and count of each number
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	unordered_map<int,int> m;
        for (int i : candidates) {
        	if (m.count(i)) m[i]++;
        	else m[i] = 1;
        }
        vector<int> nums(m.size()), count(m.size());
        int i = 0;
        for (auto& p: m) {
        	nums[i] = p.first;
        	count[i] = p.second;
            ++i;
        }
        
        vi cur;
        vvi res;
        helper(nums, count,target,0,0,cur,res);
        return res;
    }
private:
	void helper(vector<int>& nums, vector<int>& count, int target, int i, int curSum, vi& cur, vvi& res ) {
		if (i == nums.size()) {
			if (curSum == target) res.push_back(cur);
			return;
		}
		//try use ni  0 to count[i] times
		for (int j = 0; j <= count[i] && curSum + j*nums[i] <= target; ++j) {
        
			for (int k = 0; k < j; ++k) cur.push_back(nums[i]);
			curSum += j*nums[i];
			helper(nums, count, target, i+1, curSum, cur, res);
			for (int k = 0; k < j; ++k) cur.pop_back();
			curSum -= j*nums[i];
			
			
		}
	}   
};

/*

idea
Input: candidates = [10,1,2,7,6,1,5], target = 8,
[1,1,2,5,6,7,10]

for repeating numbers, take 1, 1 1

A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Input: candidates = [2,5,2,1,2], target = 5,
1,2,2,2,5
A solution set is:
[
  [1,2,2],
  [5]
]
*/

