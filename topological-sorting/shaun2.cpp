/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        vector<DirectedGraphNode*> res;
        
        queue<DirectedGraphNode*> q;
        unordered_map<DirectedGraphNode*,int> indegree;
        for (auto node: graph) {
            for (auto nb: node->neighbors) {
                indegree[nb]++;
            }
        }
        for (auto node: graph) {
            if (indegree[node] == 0) q.push(node);
        }
        
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                DirectedGraphNode* node = q.front();q.pop();
                res.push_back(node);
                for (auto nb: node->neighbors) {
                    indegree[nb]--;
                    if (indegree[nb] == 0) q.push(nb);
                }
            }
        }
        return res;
        
    }
};

/*
shaun code after several month, accepted first sub, beats 25%
indegree to store nodes whose indegree is 0, indegree as queue
finish all nodes in indegree you have at the moment, put nodes into sorted list
once a node is output, all its neighbors indegree --
put all its neighbors into the queue
*/
