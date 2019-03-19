#include<iostream>
#include<vector>
using namespace std;
//Permutation P(m,n) template
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;

//take n number out of nums for permu
//used[i] ith number used in the path
void dfs(vi& nums, int n,vb& used, vi& cur, vvi& res) {
	if (cur.size() == n) {
		res.push_back(cur);
		return;
	}	
	for (int i = 0; i < nums.size(); ++i) {
		if (used[i]) continue;
		used[i] = true;
		cur.push_back(nums[i]);
		dfs(nums,n,used,cur,res);
		cur.pop_back();
		used[i] = false;
	}	
}
/*            call stack used,cur, nums = {1,2}, P(2,2)
 *                [],[]
 *          use 1 /        2 \
 *         1,[1]          2,[2]
 *        2 |               |
 *        12,[1,2]        12,[2,1]
 */
//permu of string
void dfs(string& s, int n,vb& used, string& cur, vs& res) {
if (cur.size() == n) {
	res.push_back(cur);
	return;
}
for (int i = 0; i < s.size(); ++i) {
	if (used[i]) continue;
	used[i] = true;
	cur.push_back(s[i]);
	dfs(s,n,used,cur,res);
	cur.pop_back();
	used[i] = false;
}
}
int main() {
	vi nums{1,2,3};
	vi cur;
	vvi res;
	vb used(nums.size());
	int n = 2;
	dfs(nums,n,used,cur,res);
	cout<<"permutation: P(m," <<n <<"):" << endl;
	for (vi& row: res) {
		for (int i: row) {
			cout << i;
		}
		cout << endl;
	}
	string s = "abc";
	fill(used.begin(), used.end(),false);
	string cur1;
	vs res1;
	dfs(s,s.size(),used,cur1,res1);
	for (string& row: res1)
		cout << row << endl;
}

