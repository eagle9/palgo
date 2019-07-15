//lai heirholzer algorithm for graph eularian path
//runtime 40ms, faster than 27%, mem less than 96%
// awesome if you know this and implemenation
// but it is not something you can come up in the fly
/*
supposed to be faster, but not
Hierholzer algorithm
path = []
DFS{u}:
  while {u has fresh edge e(u,v)} {
    mark e(u,v) as visited
  DFS(v)
  }
  path.insert(path.begin(),u)
  
graph construction: O(n + nlogn)
dfs: O(n), visit edge not yet visited
space: O(n), graph and dfs stack depth is n

Eulerian path: is a trail in a finite graph which visits every edge exactly onceall tickets used and used only once
a directed graph has an eulerian path if and only if:
1) the graph is connected
2) satisfying one of the two conditions:
  a) there is one and only one node whose indegree is 1 less than its outdegree,path start; there is one and only one node whose indegree is 1 more than its outdegree, as the end of the path. All other nodes indegree == outdegree
  b) all nodes: indegree == outdegree

if we know there exists Eulerian path, then we either use Fleury or Hierholzer algorithm

*/
typedef priority_queue<string,vector<string>, greater<string>> minheap;
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        //graph_: a node to all its children(destinations)
        for(const auto& v2 : tickets) {
            graph_[v2[0]].push(v2[1]);
        }
        
        const string kStart = "JFK";
        
        vector<string> path;
        //int len = 1 + tickets.size();
        dfs(kStart,path);
        return path;
    }
private:
    // src -> {dst1, dest2, ..., destn}
    unordered_map<string, minheap> graph_;    
    
    //hierholzer dfs for eularian path
    void dfs(const string& src, vector<string>& path) {
        minheap& dests = graph_[src];
        while (!dests.empty()) {
            string dest = dests.top(); dests.pop();
            dfs(dest, path);
        }
        path.insert(path.begin(), src);
    }
};
