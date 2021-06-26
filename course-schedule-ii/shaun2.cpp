//shaun idea directly use 1 idea and code
//first sub wrong answer failling cs.size != numCourses case
//modified and accepted
//runtime 36ms, faster than 27%, mem less than 70%

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indegree(numCourses);
        unordered_map<int,vector<int>> nb;
        for (auto p: prerequisites) {
            //p.second -> p.first
            indegree[p.first]++;
            nb[p.second].push_back(p.first);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> cs;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int course = q.front(); q.pop();
                cs.push_back(course);
                for (int j: nb[course]) {
                    indegree[j]--;
                    if (indegree[j] == 0) q.push(j);
                }
            }
        }
        if (cs.size() == numCourses) return cs;
        else return vector<int>();
    }
};

