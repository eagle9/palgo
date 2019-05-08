/**
 * Definition of TreeNode:
*/
#include <iostream>
#include <vector>
#include <stack>
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
}

class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        // write your code here
        if (A.size() == 0) {
            return nullptr;
        }
        vector<TreeNode*> St;
        for (int a : A) {
            TreeNode* node = new TreeNode(a);
            while (!St.empty() && St.back()->val < a) {
                node->left = St.back();
                St.pop_back();
            }
            
            if (!St.empty()) {
                St.back()->right = node;
            }
            
            St.push_back(node);
        }
        
        return St[0];
    }
};

//print tree level order, todo
void printTreeLevel(TreeNode* root) {
}

int main() {
	vector<int> A = {2, 5, 6, 0, 3, 1};
	TreeNode* root = Solution().maxTree(A);
	printTree(root);
	return 0;
}
