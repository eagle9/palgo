//原文：https://blog.csdn.net/fuxuemingzhu/article/details/82597238 
//runtime 64ms, faster than 28%
class Solution1 {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        map<pair<int, int>, int> move;
        vector<pair<int, int>> A1s, B1s;
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j])
                    A1s.push_back({i, j});
                if (B[i][j])
                    B1s.push_back({i, j});
            }
        }
        
        int res = 0;
        for (auto a : A1s) {
            for (auto b : B1s) {
                pair<int, int> dir = make_pair(b.first - a.first, b.second - a.second);
                move[dir]++;
                res = max(res, move[dir]);
            }
        }
        return res;
    }
};


class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int N = A.size();
        unordered_map<int, int> move;
        vector<int> A1s, B1s;
        for (int i = 0; i < N * N; ++i) {
            if (A[i / N][i % N])
                A1s.push_back((i / N) * 100 + i % N);
            if (B[i / N][i % N])
                B1s.push_back((i / N) * 100 + i % N);
        }
        int res = 0;
        for (auto a : A1s) {
            for (auto b : B1s) {
                move[b - a]++;
                res = max(res, move[b - a]);
            }
        }
        return res;
    }
};

