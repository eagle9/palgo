

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
shaun came up x value concept, not clear with dfs or bfs, 
cutting: from the problem, the nodes are group with x value, go left x-1, go right x+1
bfs is preferred due it it simplicity

similar to "binary tree vertical traversal", but for each column/row, this problem has more requirements. 

Shaun own idea, accepted after 2-3 bug fixes

runtime 0ms, faster than 100%, mem less than 58%

*/
struct entry{
    int y, x;
    int val;
    entry(int y, int x, int val): y(y), x(x), val(val) {};
    bool operator < (entry other) const { //bug1 opertor () or <, kind of vague
        if (y == other.y) return val < other.val; //smaller value in front if same y level
        return y > other.y; //greater y in front
    }
};
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        map<int, set<entry>> m; //sorted map, key to sorted set
        queue<pair<int, TreeNode*>> q; //queue item x and node
        q.push({0, root});
        int y = 100;
        while (!q.empty()) {
            int size = q.size();
            y--;
            for (int i = 0; i < size; ++i) {
                auto a = q.front(); q.pop();
                int x = a.first;
                TreeNode*& node = a.second;
                m[x].insert(entry(y, x, node->val));
                if (node->left) q.push({x - 1, node->left});
                if (node->right) q.push({x + 1, node->right});
            }
        }
        for (auto a : m) {//keys are sorted
            int x = a.first;
            set<entry> set1 = a.second;
            vector<int> col;  //bug 2, vector<int> col(k), going to be [0 0 0, ...]
            for (auto& e: set1) {
                col.push_back(e.val);
            }
            res.push_back(col);
        }
        return res;
    }
};

