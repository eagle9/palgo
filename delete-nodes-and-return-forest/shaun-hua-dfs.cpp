/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 hua dfs idea, shaun understand, there is another similiar problem ----???
 runtime 24ms, faster than 72%, mem less than 100%
 
 */
class Solution {
public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> ans;
    unordered_set<int> s{begin(to_delete), end(to_delete)};
    
    TreeNode* r = dfs(root, s, ans);
    if (r) ans.push_back(r);
    return ans;
  }
private:
    TreeNode* dfs(TreeNode* n,  unordered_set<int>& s, vector<TreeNode*>& ans){
      if (!n) return nullptr;
      if (n->left) n->left = dfs(n->left, s, ans);
      if (n->right) n->right = dfs(n->right, s, ans);
      if (!s.count(n->val)) return n;
      //now n should be deleted, n->left and n->right added to ans, return NULL
      if (n->left) ans.push_back(n->left);
      if (n->right) ans.push_back(n->right);      
      return nullptr;
    };
};
