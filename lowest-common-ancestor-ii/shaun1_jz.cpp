/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */


/**
 * Definition of ParentTreeNode:
 * 
 * class ParentTreeNode {
 *     public ParentTreeNode parent, left, right;
 * }
 */
//jz code, shaun read and understood, beats 12%
class Solution {
    /**
     * @param root: The root of the tree
     * @param A, B: Two node in the tree
     * @return: The lowest common ancestor of A and B
     */
public:
    ParentTreeNode* lowestCommonAncestorII(ParentTreeNode* root,
                                                 ParentTreeNode* A,
                                                 ParentTreeNode* B) {
        vector<ParentTreeNode*> pathA = getPath2Root(A);
        vector<ParentTreeNode*> pathB = getPath2Root(B);
        
        int i = pathA.size() - 1;
        int j = pathB.size() - 1;
        
        ParentTreeNode* res = NULL;
        while (i >= 0 && j >= 0) {
            if (pathA[i]!= pathB[j]) {
                break; //no common ancestor
            }
            res = pathA[i];
            i--; j--; //try lower
        }
        
        return res;
    }
    
private:
    vector<ParentTreeNode*> getPath2Root(ParentTreeNode*& node) {
        vector<ParentTreeNode*> path;
        while (node) {
            path.push_back(node);
            node = node->parent;
        }
        return path;
    }
};
