#include<iostream>
#include<vector>
using namespace std;
//Combination C(m,n) template
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

//take n numbers out of nums
void dfs(vi& nums, int n,int start, vi& cur, vvi& res) {
	if (cur.size() == n) {
		res.push_back(cur);
		return;
	}	
	for (int i = start; i < nums.size(); ++i) {
		cur.push_back(nums[i]);
		dfs(nums,n,i+1,cur,res);
		cur.pop_back();
	}	
}
/*
 recursion call stack tree  dfs(s,cur)
 nums = 1,2,3, n =2
 			s=0,cur=[]	
		/i=0        |i=1       \ i=2
   s=1,[1]        s=2,[2])   s=3,[3]
/i=1      \i=2      | i=2          | i=3   no loop no more recur 
s=2,[1,2] s=3,[1,3] s=3,[2,3]
cur.sz=2    cur.sz=2 cur.sz =2 
*/
int main() {
	vi nums{1,2,3};
	vi cur;
	vvi res;
	int n = 2;
	dfs(nums,n,0,cur,res);
	cout<<"combination: C(m," << n <<"):" <<endl;
	for (vi& row: res) {
		for (int i: row) {
			cout << i;
		}
		cout << endl;
	}
}
