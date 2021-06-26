//hua dfs idea, cutting -- figure out cycle or loop, or any node that can reach the loop
//on the loop, the node is unsafe
//  from cur to next, if next is unsafe, then cur is unsafe 
//runtime is 160ms, faster than 93%, mem less than 100%
class Solution1 {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {    
    vector<State> states(graph.size(), UNKNOWN);
    vector<int> ans;
    for (int i = 0; i < graph.size(); ++i)      
      if (dfs(graph, i, states) == SAFE)
        ans.push_back(i);
    return ans;
  }
private:
  enum State {UNKNOWN, VISITED, SAFE, UNSAFE};
  State dfs(const vector<vector<int>>& g, int cur, vector<State>& states) {
    if (states[cur] == VISITED) return states[cur] = UNSAFE;
    if (states[cur] != UNKNOWN) return states[cur];
     
    states[cur] = VISITED;
      //g[0] = [1,2]
    for (int next : g[cur])
      if (dfs(g, next, states) == UNSAFE) 
        return states[cur] = UNSAFE;
    return states[cur] = SAFE;
  }
};

//shaun's version, not easy to come up with 4 states
class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {    
    vector<bool> visited(graph.size(), false);
    vector<State> states(graph.size(), UNKNOWN); 
    vector<int> ans;
    for (int i = 0; i < graph.size(); ++i)      
      if (dfs(graph, i,  states) == SAFE)
        ans.push_back(i);
    return ans;
  }
private:
  enum State {VD,UNKNOWN, SAFE, UNSAFE};
  State dfs(const vector<vector<int>>& g, int cur, vector<State>& states) {
    if (states[cur] == VD ) return states[cur] = UNSAFE;
    if (states[cur] != UNKNOWN) return states[cur];
     
    states[cur] = VD;
      //g[0] = [1,2]
    for (int next : g[cur]) {
      if (dfs(g, next,states) == UNSAFE) 
        return states[cur] = UNSAFE;
    }
      
    return states[cur] = SAFE;
  }
};
