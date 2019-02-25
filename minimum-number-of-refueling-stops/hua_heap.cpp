/*
huahua use pq/heap
Runtime: 32 ms, faster than 100.00% of C++ online submissions for Minimum Number of Refueling Stops.


*/

class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int cur = startFuel;
    int stops = 0;
    int i = 0;
    priority_queue<int> q; // gas (high to low) of reachable stations.
    while (true) {
      if (cur >= target) return stops;
      while (i < stations.size() && stations[i][0] <= cur)
        q.push(stations[i++][1]); 
      if (q.empty()) break;
      cur += q.top(); q.pop();
      ++stops;
    }
    return -1;
  }
};

