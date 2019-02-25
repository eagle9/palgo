// Forward declaration of the knows API.
bool knows(int a, int b);
/*
grandyang idea1
Runtime: 76 ms, faster than 95.72% of C++ online submissions for Find the Celebrity.
Memory Usage: 12 MB, less than 17.31% of C++ online submissions for Find the Celebrity.


*/
class Solution {
public:
    int findCelebrity(int n) {
        vector<bool> candidate(n, true);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (candidate[i] && i != j) {
                    if (knows(i, j) || !knows(j, i)) {
                        candidate[i] = false;
                        break;
                    } else {
                        candidate[j] = false;
                    }
                }
            }
            if (candidate[i]) return i;
        }
        return -1;
    }
};
