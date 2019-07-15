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
//grandyang dfs, constant space except stack
//cutting --- use upper level established link info
//runtime 396ms, faster than 84%, mem less than 66%
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        //user upper level link, go down 1 level to get next for current level
        Node *p = root->next;
        while (p) {
            if (p->left) { //if p->left exist, take it and done
                p = p->left;
                break;
            }
            if (p->right) { //if right exists, take it and done
                p = p->right;
                break;
            }
            //not found, move right at upper level
            p = p->next;
        }
        
        /*
                       (root) --- (root->next)
                       /    \
                      left  right 
         
        */
        
        if (root->right) root->right->next = p; 
        if (root->left) root->left->next = root->right ? root->right : p; 
        connect(root->right);
        connect(root->left);
        return root;
    }
};
