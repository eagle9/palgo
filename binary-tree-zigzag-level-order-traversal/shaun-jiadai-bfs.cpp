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
/*jiadai c++, understood
level by level, alternate direction
Runtime: 12 ms, faster than 96.82% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 13.6 MB, less than 28.86% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
*/


class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result; //result is vector of vector of int
        if (root == nullptr) {
            return result;
        }
        
        queue<TreeNode *> Q;
        Q.push(root); //push --- insert a new e at the end of queue
        bool fromLeft = true;
        while (!Q.empty()){
            int qs = Q.size(); //number of e in the queue
            vector<int> path(qs);
            for (int i = 0; i < qs; ++i){
                TreeNode *node = Q.front();
                Q.pop(); //The element removed is the "oldest" element in the queue whose value can be retrieved by calling member queue::front.
                int index = fromLeft ? i : qs - 1 - i;
                path[index] = node->val;
                if (node->left) {
                    Q.push(node->left);
                } if (node->right) {
                    Q.push(node->right);
                }
            }

            fromLeft = !fromLeft;  //done with this level, alternate direction
            result.push_back(path); //vector insert e at the end
        }
        
        return result;
    }
};

