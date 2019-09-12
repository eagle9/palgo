/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//runtime 16ms, faster than 84%, mem less than 6%
//use maxheap to store
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        //priority_queue<pair<double, int>> pq; //default pq reverse order
        priority_queue<pair<double, int>, vector<pair<double,int>>, less<pair<double,int>>> pq; //verbose, maxheap(max at top), underlying data order is less in front; if you want minheap(min at top), underlying data order is greater in front
        inorder(root, target, k, pq);
        //maxheap pq stores the k smallest differences, k closested elements
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    void inorder(TreeNode *root, double target, int k, priority_queue<pair<double, int>> &pq) {
        if (!root) return;
        inorder(root->left, target, k, pq);
        pq.push({abs(root->val - target), root->val});
        if (pq.size() > k) pq.pop();
        inorder(root->right, target, k, pq);
    }
};
