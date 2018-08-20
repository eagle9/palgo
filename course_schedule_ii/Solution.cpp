//jiadai c++ Your submission beats 60.20% Submissions!
class Solution {
public:
    /**
     * @param numCourses a total of n courses
     * @param prerequisites a list of prerequisite pairs
     * @return the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // Write your code here
        vector<unordered_set<int>> graph(numCourses);
        for (auto &p : prerequisites) {
            graph[p.second].insert(p.first);
        }
        
        vector<int> degrees(numCourses);
        for (auto &g : graph) {
            for (int node : g) {
                ++degrees[node];
            }
        }
        
        queue<int> Q;
        for (int i = 0; i < numCourses; ++i) {
            if (degrees[i] == 0) {
                Q.push(i);
            }
        }
        
        int count = 0;
        vector<int> result(numCourses);
        while(!Q.empty()) {
            int course = Q.front();
            Q.pop();
            result[count++] = course;
            for (int node : graph[course]) {
                if (--degrees[node] == 0) {
                    Q.push(node);
                }
            }
        }
        
        if (count != numCourses) {
            return {};
        }
        
        return result;
    }
};
