//shaun own, first 2 subs typo resulted error
//self check code before ok to io or submission
//write and sound the code to your brain check
//runtime 152ms, faster than 65%, mem less than 100%
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        vector<vector<int>> res(m,vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = smooth(M,i,j);
            }
        }
        return res;
    }
private:
    int smooth(vector<vector<int>>& M, int i, int j) {
        int res = 0, count = 0;
        for (int di = -1; di <= 1; ++di) {
            if (i + di < 0 || i + di >= M.size()) continue;
            for (int dj = -1; dj <= 1; ++dj) {
                if (j + dj < 0 || j + dj >= M[0].size()) continue;
                res += M[i+di][j+dj];
                count++;
            }
        }
        return res/count;
    }
};
