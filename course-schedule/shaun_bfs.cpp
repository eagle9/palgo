/*
Runtime: 20 ms, faster than 100.00% of C++ online submissions for Course Schedule.
Memory Usage: 8.9 MB, less than 4.63% of C++ online submissions for Course Schedule.
shaun c++ from jz java
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);  //vector of next for each node
        vector<int> degree(numCourses,0);
        //int degree[numCourses] = {0};
        for (auto p: prerequisites) {
            //p0 <-- p1
            int p0 = p.first, p1 = p.second;
            ++degree[p0];
            edges[p1].push_back(p0);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (degree[i] == 0) q.push(i);
        }
        int count = 0;
        while (!q.empty()){
            int node = q.front(); q.pop();
            count++;
            for (int next: edges[node]) {
                --degree[next];
                if (degree[next] == 0) {
                    q.push(next);
                }
            }
        }
        return count == numCourses;
        
    }
};

