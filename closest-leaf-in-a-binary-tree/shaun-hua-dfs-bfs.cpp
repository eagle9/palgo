/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//hua idea, cutting shortest path in a tree, or graph, as asked in the problem, we need to go from child to parent, so naturally we need construct a graph, or for each node in the tree, we construct a neighbor list for each node
//once we have the graph, the problem boils down to use bfs(level by level) to find shortest path
//runtime 20ms, faster than 62%, mem less than 47%
class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        //graph_.clear();
        start_ = nullptr;
        buildGraph(root, nullptr, k);
        queue<TreeNode*> q;
        q.push(start_);
        unordered_set<TreeNode*> seen;
        while (!q.empty()) {
            int size = q.size();
            while (size-->0) {
                TreeNode* curr = q.front();
                q.pop();                
                seen.insert(curr);                
                if (curr->left == nullptr && curr->right == nullptr) return curr->val;
                for (TreeNode* node : graph_[curr])
                    if (!seen.count(node)) q.push(node);
            }
        }
        return 0;
    }
private:
    //build the graph: parent -> child in tree, we need to store child->parent too
    //key to add parent in the dfs call
    //also need to find start_ node
    void buildGraph(TreeNode* node, TreeNode* parent, int k) {
        if (!node) return; //base exit
        
        if (node->val == k) start_ = node;
        if (parent) {
            graph_[node].push_back(parent);
            graph_[parent].push_back(node);
        }
        buildGraph(node->left, node, k);
        buildGraph(node->right, node, k);
    }
    
    unordered_map<TreeNode*, vector<TreeNode*>> graph_;
    TreeNode* start_;
};
