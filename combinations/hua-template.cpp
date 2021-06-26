//hua's combination template, slight different from my own, i check outbound at recursion exit 
//runtime 88ms, faster than 62%, mem less than 95%
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vvi res;
        vi cur;
        dfs(n, k, 1, cur, res);
        return res;
    }
private:
    //C(m,n) take n out of m, no order combinations
    //n: n numbers to take from m
    //start:running index from 0 to nums.size()-1
    void dfs(int m, int n,int start,vi& cur,vvi& res) {
        if (cur.size() == n){
            res.push_back(cur);
            return;
        }
        //try all possible numbers from start
        //for (int i = start; i < nums.size(); i++) {
        for (int i = start; i <= m; i++) {
            cur.push_back(i);
            //decisions made for all idx <= i, use nums[i]
            dfs(m,n,i+1,cur,res);
            //not use nums[i]
            cur.pop_back();
        }
    }
};
