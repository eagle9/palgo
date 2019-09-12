//grandyang using inorder traversal to get array, then take the k closest to the target
//runtime 12ms, faster than 97%, mem less than 94%
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res, v;
        inorder(root, v);
        
        int idx = 0;
        double min_diff = numeric_limits<double>::max();
        //find the element of v that is closest to target
        for (int i = 0; i < v.size(); ++i) {
            double diff = abs(target - v[i]);
            if (diff <= min_diff ) {
                min_diff = diff;
                idx = i;
            }
        }
        int left = idx - 1, right = idx + 1;
        //find k elements
        for (int i = 0; i < k; ++i) {
            //idx is the closest
            res.push_back(v[idx]);
            
            //compare left and right, choose the index of the smaller element
            if (left >= 0 && right < v.size()) {
                if (abs(v[left] - target) > abs(v[right] - target)) {
                    idx = right;
                    ++right;
                } else {
                    idx = left;
                    --left;
                }
            } else if (left >= 0) { //right side used up, go left only
                idx = left;
                --left;
            } else if (right < v.size()) { //left side used up, go right only
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
