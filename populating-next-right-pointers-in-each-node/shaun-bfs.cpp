/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
//grandyang and shaun both come up with bfs level order idea
// nodes at the same level stored in queue snapshot
//how to chain them
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node *t = q.front(); q.pop();
                //if not the right most node
                if (i < size - 1) {
                    t->next = q.front();
                }
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return root;
    }
};
