Input: root to binary tree; 
task: serialize tree into a file, then de-serialize and re-create same tree
struct TreeNode {
    TreeNode* left;
    TreeNode  * right;
    int va;
    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right= NULL;
    }
    
}
/*
   1
  2 3
 45  7
 res: 1 2 3 4 5 # 7
 q:   
 
 token: 1 2 3 4 5 # 7
 q:  4 5 7  
 
     1
   2    3
  4  5     7
*/
string serialize(TreeNode* root) {
    string res;
    if (root == NULL) return res; 
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* t = q.top(); q.pop();
        //what if t == NULL
        if (t != NULL) {
            res += res.empty()? "": " " + t->val;
            q.push(t->left);
            q.push(t->right);
        }
        else
            res += res.empty()? "": " " + "#";
        
    }
    //q empty
    return res;
}

TreeNode* deserialize(string input) {
    stringstream ss(input);
    string token;
    queue<TreeNode*> q;
    getline(ss, token, '');
    if (token == "#") return NULL;
    TreeNode* root = new TreeNode(stoi(token));
    q.push(root);
    while (getline(ss, token, ' ')) {
        TreeNode* left = NULL, *right = NULL;
        if (token != "#") {
            left = new TreeNode(stoi(token));
        }
        if (getline(ss,token,' ')) {
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
