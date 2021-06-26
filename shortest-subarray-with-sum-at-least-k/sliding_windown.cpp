/*
https://blog.csdn.net/yanglingwell/article/details/80875790
sliding window idea O(n)

Runtime: 148 ms, faster than 24.47% of C++ online submissions for Shortest Subarray with Sum at Least K.
Memory Usage: 23.9 MB, less than 16.40% of C++ online submissions for Shortest Subarray with Sum at Least K.
*/

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<long long int> frontSum(A.size()+1, 0);

        for(int i = 1; i <= A.size(); ++i)
        {
            frontSum[i] = frontSum[i-1] + A[i-1];
        }

        int ans = -1;

        deque<int> begCandidates; 

        // 每一次循环处理： 以 end 为结束的 Shortest Subarray with Sum at Least K
        for(size_t end = 0; end <= A.size(); ++end)
        {
            // 如果 begCandidates.back() 到 end 的和是负的，
            // 则计算 end 之后的 “以 end 为结束的 Shortest Subarray with Sum at Least K”， 
            // 不再需要从 begCandidates.back() 开头子数组
            while(!begCandidates.empty() && frontSum[end] - frontSum[begCandidates.back()] <= 0)
            {
                begCandidates.pop_back();
            }

            // 如果 begCandidates.front() 到 end 的和大于等于 K， 则其可能是备选方案
            while(!begCandidates.empty() && frontSum[end] - frontSum[begCandidates.front()] >= K)
            {
                // 如果 begCandidates.front() 到 end 的和大于等于 K, 
                // 则后面的计算不再需要 begCandidates.front() 
                // 因为，begCandidates.front()为起始，和大于等于 K 的，
                // 最小距离一定小于等于 end - begCandidates.front()。
                int beg = begCandidates.front();
                begCandidates.pop_front();

                if(ans == -1) ans = end - beg;
                else ans = min(ans, (int)end - beg);
            }

            begCandidates.push_back(end);
        }

        return ans;

    }
};

