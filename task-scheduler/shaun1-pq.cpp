/*
https://leetcode.com/problems/task-scheduler/discuss/104493/c-java-clean-code-priority-queue
The idea is:
0. To work on the same task again, CPU has to wait for time n, therefore we can think of as if there is a cycle, of time n+1, regardless whether you schedule some other task in the cycle or not.

To avoid leave the CPU with limited choice of tasks and having to sit there cooling down frequently at the end, it is critical the keep the diversity of the task pool for as long as possible.
In order to do that, we should try to schedule the CPU to always try round robin between the most popular tasks at any time.

shaun has understood
runtime 152ms, faster than 19%, mem less than 6%
not the fastest, but useful if asked to output the task sequence
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char t : tasks) {
            counts[t]++;
        }
        priority_queue<pair<int, char>> pq;
        //take the task with max count first
        for (pair<char, int> count : counts) {
            pq.push(make_pair(count.second, count.first));
        }
        int ans = 0; //number of intervals
        //problem statement ---> n intervals between two same tasks
        //why cycle =n+1????
        int cycle = n+1; // a cycle has n tasks, [0 1 .. n-1 n] [0' ...] ---> a cycle length is n+1
        while (!pq.empty()) {
            int count = 0; // count of tasks assigned
            vector<pair<int, char>> block; // block of tasks for this cycle
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    block.push_back(pq.top());pq.pop();
                    count++;
                }
            }
            //for each task in the assigned block, -- its count, push back into heap
            for (auto p : block) {
                if (--p.first > 0) {
                    pq.push(p);
                }
            }
            //ans += count;  ---- won't work, why???
            //pq heap stores the tasks to be scheduled, if there still are tasks to be scheduled, apparently, we need maintain the block size ==  cycle, otherwise, just count of tasks assigned for this cycle
            ans += !pq.empty() ? cycle : count;
        }
        return ans;
    }
};
