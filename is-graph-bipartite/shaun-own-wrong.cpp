/*
shaun own idea forming cutting: 
split all nodes into 2 independent sets, each edge one node in A and one node in B

for each edge ab,  try a to set A, b to B, or a to B, b to A
A and B includes all nodes, A B do not have common nodes
wrong answer
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> A, B;
        bool ans = false;
        helper( graph, 0, A, B, ans);
        return ans;
    }
private:
    void helper(vector<vector<int>>& graph, int i, unordered_set<int>& A, unordered_set<int>& B, bool& ans) {
        
        if (i == graph.size()) {
            for (int a: A) {
                if (B.count(a)) return; //exit A B not independent
            }
            //A B independent now
            ans = true;
        }
        if (ans) return;
        
        for (int j: graph[i]) {
        
            A.insert(i); 
            B.insert(j);
            helper(graph, i+1, A, B, ans);
            A.erase(i); B.erase(j);
            A.insert(j); B.insert(i);
            helper(graph, i+1, A, B, ans);
        
        }
        
    }
};
