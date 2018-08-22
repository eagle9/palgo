#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//yubin bai's c++ modified to lintcode parameter signature
//Your submission beats 21.40% Submissions!
//however g++ --std=c++11 does not compile!!!
class Solution {
public:
  bool validTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }
    vector<bool> on_path(n, false), visited(n, false);
    if (hasCycle(adj, 0, -1, on_path, visited)) {
      return false;
    }
    for (bool v : visited) {
      if (!v) {
        return false; 
      }
    }
    return true;
  }

private:
  bool hasCycle(vector<vector<int>>& adj, int k, int parent,
                vector<bool>& on_path, vector<bool>& visited) {
    if (on_path[k]) {
      return true;
    }
    on_path[k] = visited[k] = true;
    for (auto v : adj[k]) {
      if (v != parent && hasCycle(adj, v, k, on_path, visited)) {
        return true;
      }
    }
    return on_path[k] = false;
  }
};

//yubin bai's c++ modified to lintcode parameter signature
int main() {
  Solution sol;
  vector<vector<int, int>> v1 = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
  cout << sol.validTree(5, v1) << endl;

  vector<vector<int, int>> v2 = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
  cout << sol.validTree(5, v2) << endl;
  return 0;
}
