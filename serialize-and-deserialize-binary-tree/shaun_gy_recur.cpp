/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun tried to write from grandyang recursion idea, 
//accepted after a number of fixes, not familiar with stringstream
//runtime 44ms, faster than 85%, mem less than 58%
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }
    
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
    
private: 
    void serialize(TreeNode* root, ostringstream& out) {
        if (root == NULL) out << "# "; //one space after #
        else {
            out << root->val << " ";
            serialize(root->left, out);
            serialize(root->right, out);
        }
    }
    
    TreeNode * deserialize(istringstream& in) {
        string s; 
        in >> s;
        if (s == "#") return NULL;
        
        TreeNode* node = new TreeNode(stoi(s));
        node->left = deserialize(in);
        node->right= deserialize(in);
     
        return node;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
