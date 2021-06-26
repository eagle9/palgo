//https://www.sigmainfy.com/blog/leetcode-subset-i-and-ii.html
//no recursive, Your submission beats 100.00% Submissions!
/*Another different angle to remove duplicates is to treat the continues duplicates number S[i] which appears t times as a whole, and this whole thing have 1 + t choices for us, to put 0..t of them into the subsets. This implementation could be integrated into the 3rd approach fro Subsets I discussed previously and the following iterative implementations is accepted by LeetCode OJ to pass both the Subsets I and II problems:
*/
class Solution {
    public:
    vector<vector<int> > subsetsWithDup(vector<int> & S) {
        sort(S.begin(), S.end());
        vector<vector<int>> vv(1);
        int i= 0, cnt = 0;
        int n = S.size();
        while (i < n) {
            cnt = 1;
            while (i + cnt < n && S[i] == S[i + cnt]) ++cnt;
            for (int k = vv.size() - 1; k >= 0; --k) {
                vector<int> tmp = vv[k];
                for (int j = 1; j <= cnt; ++j) {
                    tmp.push_back(S[i]);
                    vv.push_back(tmp);
                }
            }
            i += cnt;
        }
        return vv;
    }
};
