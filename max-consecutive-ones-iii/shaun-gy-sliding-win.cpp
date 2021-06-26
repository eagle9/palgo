
//gy sliding window, runtime 60ms, faster than 67%, mem less than 100%
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0, zero = 0, left = 0, k = K;
        for (int right = 0; right < A.size(); ++right) {
            if (A[right] == 0) ++zero;
            while (zero > k) {
                if (A[left++] == 0) --zero;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
