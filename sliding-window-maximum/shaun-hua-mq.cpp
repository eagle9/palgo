//hua sliding window with monotonic queue
//shaun write from the idea, accepted after 1 bug fix
//runtime 56ms, faster than 92%, mem less than 97%
class MonotonicQueue {
public:
    void push(int e) {
        while(!dq.empty() && dq.back() < e) dq.pop_back();
        //dq.empty or e>= dq.back().
        dq.push_back(e);
    } 
  
    void pop() {
        dq.pop_front();
    }
  
    int max() { return dq.front(); }
    
private: 
    deque<int> dq;
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        MonotonicQueue q;
        int n = nums.size();
        vector<int> res(n-k+1);
        int idx = 0;
        for (int i = 0; i < n; i++) {
            q.push(nums[i]); //expand to right
            //  left   --- right
            //  i-k+1 ---   i
            //enough number in the window
            if (i  >= k-1) {
                res[idx++] = q.max();
                //contract left
                if (nums[i - k + 1] == q.max()) q.pop(); //bug 1, should add this line
            }
        }
        return res;
    }

};
