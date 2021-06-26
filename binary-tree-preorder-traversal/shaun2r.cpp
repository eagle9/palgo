//shaun 2round, accepted, runtime 4ms, faster than 100%
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode * cur = root;
        while (cur || !st.empty()){
            
            while (cur) {
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            //cur == NULL now
            cur = st.top(); st.pop();
            cur = cur->right;
        }
        return res;
    }
};
