//grandyang using inorder traversal
//beats 100%, to be translated and understood better
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res, v;
        inorder(root, v);
        int idx = 0;
        double diff = numeric_limits<double>::max();
        for (int i = 0; i < v.size(); ++i) {
            if (diff >= abs(target - v[i])) {
                diff = abs(target - v[i]);
                idx = i;
            }
        }
        int left = idx - 1, right = idx + 1;
        for (int i = 0; i < k; ++i) {
            res.push_back(v[idx]);
            if (left >= 0 && right < v.size()) {
                if (abs(v[left] - target) > abs(v[right] - target)) {
                    idx = right;
                    ++right;
                } else {
                    idx = left;
                    --left;
                }
            } else if (left >= 0) {
                idx = left;
                --left;
            } else if (right < v.size()) {
                idx = right;
                ++right;
            }
        }
        return res;
    }
    void inorder(TreeNode *root, vector<int> &v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
};
