//gy idea with q
//runtime 60ms, faster than 67%, mem less than 9%
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0, right = 0;
        int res = 0;
        queue<int> q;
        for (int right = 0; right < A.size(); right++) {
            if (A[right] == 0) q.push(right);
            while (q.size() > K) {
                left = q.front()+1;  //why +1
                q.pop();
            }
            res = max(res, right - left+1);
        }
        return res;
    }
};
