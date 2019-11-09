/*
https://www.youtube.com/watch?v=YCD_iYxyXoo
huahua greedy idea, cutting angle, keep the most frequent task n distance apart
shaun has read and understand
runtime 56ms, faster than 80%, mem less than 96%

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
        
        /*
        Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
        max_count = 3, max element reps how many times
        each group n+1 intervals
        p how many max elements
        use an example, very easy to understand
        */
        int ans = (max_count-1)*(n+1) + p;
        //if tasks count > ans, it can be proved that task count is the answer
        return max((int)tasks.size(), ans);
    }
};
