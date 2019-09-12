
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	public:

    string serialize(TreeNode* root) {
        string res = "";
        if (root == NULL) return res; 
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            //TreeNode* t = q.top(); q.pop();
            TreeNode* t = q.front(); q.pop();
            //what if t == NULL
            if (t != NULL) {
                //res += res.empty()? "": " " + t->val;
                res += string(res.empty()? "": " ") + to_string(t->val);
                q.push(t->left);
                q.push(t->right);
            }
            else
                res += string(res.empty()? "": " ") + string("#");
        }
        //q empty
        return res;
    }

    TreeNode* deserialize(string input) {
        stringstream ss(input);
        string token;
        queue<TreeNode*> q;
        getline(ss, token, ' ');
        if (token.empty() || token == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(token));
        q.push(root);
        while (getline(ss, token, ' ')) {
            TreeNode* left = NULL, *right = NULL;
            if (token != "#") {
                left = new TreeNode(stoi(token));
            }
            if (getline(ss,token,' ')) {
                //cout << token << endl;
                if (token != "#") {
                    right = new TreeNode(stoi(token));
                }
            }


            //who is my parent
            if (!q.empty()) {
                TreeNode* parent = q.front();q.pop();
                parent->left = left;
                parent->right = right;
                if (left) q.push(left);
                if (right) q.push(right);

            }
        }

        //no token anymore 
        return root;
    }
};

int main() {
	Solution s;
	string input = "1 2 3 4 5 # 7";
	TreeNode* root = s.deserialize(input);
	string res = s.serialize(root);
	cout << "serialized:" << endl;
	cout << res << endl;
}

