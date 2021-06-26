typedef vector<vector<int>> vvi;
typedef vector<int> vi;
//shaun raw first sub, wrong answer, not clear how many times each number can be taken
class Solution000 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vi cur; 
        vvi res;
        helper(n,k, 1, 0, cur, res);
        return res;
    }

private:
	//target,  # to take from 1 to 9, 
	void helper(int n, int k, int i, int curSum, vi& cur, vvi& res ) {
		//no more numbers are needed, complete
		if (i > 9) return;
		if (k == 0 ) {
			if (curSum == n) res.push_back(cur);
			return;
		}

		//to take number nums[i], 0 to inf times
		for (int j = 0; j <= 1 && curSum + j*i <= n; ++j) {
			for (int k = 0; k < j; ++k) cur.push_back(i);
			curSum += j*i;
			helper(n, k-j, i+1, curSum, cur, res);   //first fix, k-1===> k-j
			curSum -= j*i;
			for (int k = 0; k < j; ++k) cur.pop_back();
		}
	}
};

//shaun adapt raw idea and code with ref to grandyang
//accepted, runtime 4ms, faster than 100%, memory less than 99%
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vi cur; 
        vvi res;
        helper(n,k, 1, 0, cur, res);
        return res;
    }

private:
	//target,  # to take from 1 to 9, 
	void helper(int n, int k, int i, int curSum, vi& cur, vvi& res ) {
		//no more numbers are needed, complete
		//if (i > 9) return;
		if (k == 0 ) {
			if (curSum == n) res.push_back(cur);
			return;
		}

		//to take all possible numbers nums from i to 9 (all larger number than prev)
		for (int j = i; j <= 9; ++j) {
			cur.push_back(j);
			curSum += j;
			helper(n, k-1, j+1, curSum, cur, res);
			curSum -= j;
			cur.pop_back();
		}
	}
};



/*
first sub:  k = 3, n = 7:
[[2,2,3],[1,3,3],[1,2,2,2],[1,1,2,3],[1,1,1,2,2],[1,1,1,1,3],[1,1,1,1,1,2],[1,1,1,1,1,1,1]]


idea forming:

The solution set must not contain duplicate combinations (always take larger number than previous number). no number is repeated, 

example1:
Input: k = 3, n = 7
Output: [[1,2,4]]

example2:
Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]

Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

*/
