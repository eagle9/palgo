/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
//beats 96%, jiadai
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode*> result;
        unordered_map<DirectedGraphNode*, int> indegree;
        for (DirectedGraphNode* node : graph) {
            if (indegree.find(node) == indegree.end()) {
                indegree[node] = 0;
            }
            for (DirectedGraphNode* nb : node->neighbors) {
                ++indegree[nb];
            }
        }
        
        queue<DirectedGraphNode*> Q;
        for (auto it = indegree.begin(); it != indegree.end(); ++it) {
            if (it->second == 0){
                Q.push(it->first);
            }
        }
        
        while (!Q.empty()) {
            DirectedGraphNode* node = Q.front();
            Q.pop();
            result.push_back(node);
            
            for (DirectedGraphNode* nb : node->neighbors) {
                if (--indegree[nb] == 0) {
                    Q.push(nb);
                }
            }
        }
        
        return result;
    }
};
