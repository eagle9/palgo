/*
https://www.youtube.com/watch?v=YCD_iYxyXoo
huahua greedy idea, cutting angle, keep the most frequent task n distance apart
shaun has read and understand
Runtime: 52 ms, faster than 96.56% of C++ online submissions for Task Scheduler.
Memory Usage: 9.9 MB, less than 62.93% of C++ online submissions for Task Scheduler.

*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char task : tasks) {
            ++cnt[task - 'A'];
        }
        int max_count = *max_element(cnt.begin(), cnt.end());
        /*int p = 0;
        for (int x: cnt) {
            if (x == max_count) p++;
        }*/
        int p = count(cnt.begin(), cnt.end(), max_count);
        //gredy, max_count groups, each group n+1 tasks, last group p tasks
        int ans = (max_count-1)*(n+1) + p;
        //if tasks count > ans, it can be proved that task count is the answer
        return max((int)tasks.size(), ans);
    }
};
