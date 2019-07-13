//shaun idea and code, runtime 20ms, faster than 96%, mem less than 75%
//cutting --- graph topological sorting, from order between pairs, to order of all nodes
//  track indegree and use bfs
//accept first sub after changing nb from vector<int,vector<int>> to unordered_map<int, vector<int>>
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        
        return cs.size() == numCourses;
        
    }
};
