/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/*

grandyang idea, cutting: bfs, need to know the number of children of each node
runtime 236ms, faster than 57%, mem less than 100%
*/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return string("#");
        string res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node *t = q.front(); q.pop();
            res += to_string(t->val) + " " + to_string(t->children.size()) + " ";
            for (Node *child : t->children) { //child won't be NULL if any child exists
                q.push(child);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream iss(data);
        queue<Node*> qNode;
        queue<int> qSize;
        string val = "", size = "";
        iss >> val;
        if (val == "#") return NULL;
        iss >> size;
        Node *root = new Node(stoi(val), {});
        qNode.push(root);
        qSize.push(stoi(size));
        
        while (!qNode.empty()) {
            Node *t = qNode.front(); qNode.pop();
            int len = qSize.front(); qSize.pop();
            //to fill t's children, len children
            for (int i = 0; i < len; ++i) {
                if (!(iss >> val)) break;
                if (!(iss >> size)) break;
                Node* cur = new Node(stoi(val), {}); //val won't be #
                qNode.push(cur);
                qSize.push(stoi(size));
                t->children.push_back(cur);
            }
        }
        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
