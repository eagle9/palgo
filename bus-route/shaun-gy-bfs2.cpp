//shaun first try, wrong
//check with gy, not straightforward apply of the bfs template
//runtime 1636ms, faster than 5%, mem less than 100%
// stop2bus use int to vector<int> TLE
//          use int to unordered_set<int>, 5%
// shaun use visited to store bus, not stop, faster than 70%
// stop2bus use int to vector<int>, faster than 83%, mem less than 100%
//final runtime 108ms, faster than 93%, mem less than 100%
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        
        if (S == T) return 0; //no need to get on bus
        
        //unordered_map<int,unordered_set<int>> stop2bus;
        unordered_map<int,vector<int>> stop2bus;
        for (int bus = 0; bus < routes.size(); ++bus) {
            for (int stop: routes[bus]) {
                //stop2bus[stop].insert(bus);
                stop2bus[stop].push_back(bus);
            }
        }
        
        //bfs level by level from S to T
        queue<int> q;
        unordered_set<int> visited;
        q.push(S);
        int buses = 0;
        while (!q.empty()) {
            buses++;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int stop = q.front(); q.pop();
                
                for (int bus: stop2bus[stop]) {
                    if (visited.count(bus)) continue;
                    visited.insert(bus);
                    for (int next: routes[bus]) {
                        if (next == T) return buses;
                        
                        //not visited
                        q.push(next);
                        
                    }
                    
                }
            }
            
            
        }
        //not yet reach T, not possible, return -1
        return -1;
    }
};
