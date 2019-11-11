/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 shaun off hua's analysis and idea, cutting: draw the picture and turn this problem into node count
 
 runtime 0ms, faster than 100%, mem less than 100%
 */
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        count_nodes(root,x);
        int p_count = n - (left_count + right_count +1);
        //n is odd, for example 7,  7/2 = 3,   can i color >3??? 
        return max(p_count, max(left_count, right_count)) > n/2;
    }
    
private:
    int left_count, right_count; //count of nodes of x's left subtree and right subtree
    //return count number of nodes of binary tree rooted at node
    //update x's left subtree node count and right subtree node count
    int count_nodes(TreeNode* node, int x) {
        if (!node) return 0;
        int left = count_nodes(node->left,x);
        int right = count_nodes(node->right,x);
        if (node->val == x) {
            left_count = left;
            right_count = right;
        }
        return 1 + left + right;
        
    }
};
