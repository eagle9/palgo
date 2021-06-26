/**
 * Definition of TreeNode:
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};
//jz
class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    vector<TreeNode *> stk;
    TreeNode* maxTree(vector<int> A) {
        // write your code here
        int len = A.size();
        for (int i = 0; i < len; ++i) {
            TreeNode *tmp = new TreeNode(A[i]);   //新建节点
            while (stk.size() > 0 && A[i] > stk[stk.size()-1]->val) {   //如果stk中的最后一个节点比新节点小
                tmp->left = stk[stk.size()-1];      //当前新节点的左子树为stk的最后一个节点
                stk.pop_back();
            }
            if (stk.size() > 0)    					//如果stk不为空
                stk[stk.size()-1]->right = tmp;		//将新节点设为stk最后一个节点的右子树
            stk.push_back(tmp);
        }
        return stk[0];
    }
};

//jiadai, c++ vector used a stack:
//   stack.top() ==> vector.back(),   stack.pop() ---> vector.pop_back(), size() and empty() same for both vector and stack
class Solution1 {
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
			// a > top
			//                a
			//      top(back)
            while (!St.empty() && St.back()->val < a) {
                node->left = St.back();
                St.pop_back();
            }
            
            if (!St.empty()) { // a <= top
				//     a(node)
				//              top/back
                St.back()->right = node;
            }
            St.push_back(node);
        }
        
        return St[0]; //stack bottom  element direct access
    }
};
class Solution3 {
public:
	TreeNode* maxTree(vector<int> A) {
			if (A.empty()) return NULL;
			stack<TreeNode*> st;
			st.push(new TreeNode(A[0]));

			for (int i = 1; i < A.size(); ++i) {
				TreeNode* node = new TreeNode(A[i]);
				if (A[i] <= st.top()->val) {
					st.push(node);
				}else { // top-val < node.val 
					TreeNode* n1 = st.top(); st.pop();
					while (!st.empty() && st.top()->val < A[i]) {
						TreeNode* n2 = st.top(); st.pop();
						//n2 < n1
						n2->right = n1;
						n1 = n2;
					}
					//n1 < node A[i] 
					node->left = n1;
					st.push(node);
				}	
			}
			TreeNode* root = st.top(); st.pop();
			while (!st.empty()) {
				st.top()->right = root;
				root = st.top(); st.pop();
			}
			return root;
		}
};
//print tree level order, todo
void printTree(TreeNode* root) {
	queue<TreeNode*> q;
	if (root) q.push(root);
	while (!q.empty()) {
		int n = q.size();
		for (int i = 0; i < n; ++i) {
			TreeNode* node = q.front(); q.pop();
			cout << node->val;
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}	
		cout << endl;
	}
}

int main() {
	vector<int> A = {2, 5, 6, 0, 3, 1};
	TreeNode* root = Solution3().maxTree(A);
	printTree(root);
	return 0;
}
