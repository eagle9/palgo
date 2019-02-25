/*
grandyang idea1
Runtime: 56 ms, faster than 63.89% of C++ online submissions for Task Scheduler.
Memory Usage: 10.2 MB, less than 43.02% of C++ online submissions for Task Scheduler.

*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char task : tasks) {
            ++cnt[task - 'A'];
        }
        sort(cnt.begin(), cnt.end());
        int i = 25, mx = cnt[25], len = tasks.size();
        while (i >= 0 && cnt[i] == mx) --i;
        return max(len, (mx - 1) * (n + 1) + 25 - i);
    }
};
