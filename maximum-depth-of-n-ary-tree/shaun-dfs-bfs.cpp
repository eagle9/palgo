/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
//runtime 136ms, faster than 93%, mem less than 60%
class Solution1 {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        int max1 = 0;
        for (Node* child: root->children) {
            max1 = max(max1, maxDepth(child));
        }
        return 1 + max1;
    }
};

//bfs level by level version
//runtime 132ms, faster than 96%, mem less than 11%
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        queue<Node*> q({root});
        int depth = 0;
        while (!q.empty()) {
            int n = q.size();
            depth++;
            for (int i = 0; i < n; ++i) {
                Node* cur = q.front(); q.pop();
                for (Node* child: cur->children) {
                    if (child) q.push(child);
                }
            }
        }
        return depth;
    }
};
