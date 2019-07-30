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
naive solution, inorder traverse root, compare cur to p, if ==p, set a flag, one more step
in order traversal with stack, track pre, if prev == p, the cur is answer

divide and conquer, compare cur->val and p->val, if cur > p, cur is after p
else if cur>val <= p->val
runtime 24ms, faster than 99.87%, mem less than 55%
*/
class Solution1 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        helper(root, p);
        return succ;
    }
private:
    TreeNode* succ = NULL;
    void helper(TreeNode*& cur, TreeNode*& p) {
        if (cur == NULL) return;
        if (cur->val <= p->val) { // p's succ in right tree
            helper(cur->right, p);
        }else { //cur->val > p->val, succ is one candidate, 
            succ = cur;
            helper(cur->left, p);
        }
    }
};

//shaun own inorder traversal with stack, still coded out from example after 6month
//runtime 36ms, faster than 81%, mem less than 92%
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> st;
        
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur!=NULL || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            //cur == NULL now
            cur = st.top(); st.pop();
            if (pre == p) break;
            pre = cur;
            cur = cur->right;
        }
        return cur;
    }
};

