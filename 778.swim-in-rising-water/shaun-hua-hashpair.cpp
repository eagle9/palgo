//hua dijkstra idea, shaun tried to use pair<int,int> as map key
//use geeksforgeeks hash_pair to enable pair<int,int> as hash key


//runtime 36ms, faster than 34%, mem less than 34%

//https://www.geeksforgeeks.org/how-to-create-an-unordered_map-of-pairs-in-c/
#include <bits/stdc++.h> 
using namespace std; 
  
// A hash function used to hash a pair of any kind 
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

struct record {
    int time;
    int x;
    int y;
    record(int time, int x, int y): time(time),x(x),y(y) {};
    //bool operator <(record& other) const  //-->bug use & 
    bool operator <(record other) const {
        return time > other.time;
    }
};
class Solution {
public:
  int swimInWater(vector<vector<int>>& grid) {
    const int n = grid.size();
    priority_queue<record> q; // {time, x,y}, smaller time at top
    q.push(record{grid[0][0], 0,0});
    unordered_map<pair<int, int>, bool, hash_pair> seen;
    vector<int> dirs{-1, 0, 1, 0, -1};
    pair<int,int> p = make_pair(0,0);
    seen[make_pair(0,0)] = 1;
    //seen.insert(p);
    while (!q.empty()) {
      record node = q.top(); q.pop();
      int t = node.time;
      int x = node.x;
      int y = node.y;      
      if (x == n - 1 && y == n - 1) return t;
      for (int i = 0; i < 4; ++i) {
        int tx = x + dirs[i];
        int ty = y + dirs[i + 1];
        if (tx < 0 || ty < 0 || tx >= n || ty >= n) continue;
        p = make_pair(tx,ty);
        if (seen.count(p)) continue;
        seen[p] = 1;
        //seen.insert(p);
        q.push({max(t, grid[ty][tx]), tx, ty});
      }
    }
    return -1;
  }
};
