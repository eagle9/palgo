/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


/*shaun first sub with solution to 1, wrong answer, could not pass all test cases
Input
{1,#,2,#,3,#,4,#,5}
3
8
Output
3
Expected
null

*/

//shaun first sub used LCA1, wrong answer
//second sub checked with jz, wrong answer
//added 1 line, accepted, beats 6%
class Solution {
public:

    struct ResType {
        bool a_found, b_found;
        TreeNode* node;
        ResType(TreeNode* node, bool a, bool b ): node(node), a_found(a), b_found(b) {
            
        }
    };
    
    //step 1, define recur function, return and parameters
    //return LCA of A and B
    //if found lca, return lca
    //if found A, return A
    //if found B, return B
    // only found A or B, return null
    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* A, TreeNode* B) {
        ResType res = helper(root, A, B);
        if (res.a_found && res.b_found)
            return res.node;
        else
            return NULL;
    }
private:
    ResType helper(TreeNode*& root, TreeNode*& A, TreeNode*& B) {
        if (root == NULL) return ResType(NULL, false, false);
        
        ResType left = helper(root->left, A, B);
        ResType right= helper(root->right, A, B);
        bool a_found =  (root == A || left.a_found || right.a_found);
        bool b_found =  (root == B || left.b_found || right.b_found);
        
        if (root == A || root == B)
            return ResType(root, a_found, b_found);
        
        if (left.node && right.node) return ResType(root, a_found, b_found);
        if (left.node) return ResType(left.node, a_found, b_found);
        if (right.node) return ResType(right.node, a_found,b_found);
        //left.node == NULL && right.node == NULL
        return ResType(NULL, a_found, b_found);
    }
            
};
