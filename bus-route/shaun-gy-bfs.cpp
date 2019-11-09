//shaun first try, wrong
//check with gy, not straightforward apply of the bfs template
//runtime 1636ms, faster than 5%, mem less than 100%
// stop2bus use int to vector<int> TLE
//          use int to unordered_set<int>, 5%
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        
        unordered_map<int,unordered_set<int>> stop2bus;
        //unordered_map<int,vector<int>> stop2bus;
        for (int bus = 0; bus < routes.size(); ++bus) {
            for (int stop: routes[bus]) {
                stop2bus[stop].insert(bus);
                //stop2bus[stop].push_back(bus);
            }
        }
        
        if (S == T) return 0; //no need to get on bus
        
        //bfs level by level from S to T
        queue<int> q;
        unordered_set<int> visited;
        int level = 0;
        q.push(S);
        visited.insert(S);
        while (!q.empty()) {
            level++;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int stop = q.front(); q.pop();
                
                for (int bus: stop2bus[stop]) {
                    for (int next: routes[bus]) {
                        if (next == T) return level;
                        if (visited.count(next)) continue;
                        //not visited
                        q.push(next);
                        visited.insert(next);
                    }
                    
                }
            }
            
            
        }
        //not yet reach T, not possible, return -1
        return -1;
    }
};
