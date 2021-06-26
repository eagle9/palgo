/**
 * Definition of TrieNode:
 * class TrieNode {
 * public:
 *     TrieNode() {}
 *     map<char, TrieNode*> children;
 * };
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a trie which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TrieNode* root) {
        // Write your code here
        if (root == NULL)
            return "";
        string data;
        for (map<char, TrieNode*>::iterator it = root->children.begin();
            it != root->children.end(); ++it) {
            data += it->first;
            data += serialize(it->second);
        }
        return "<" + data + ">";
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TrieNode* deserialize(string data) {
        // Write your code here
        if (data.size() == 0)
            return NULL;

        TrieNode* head = new TrieNode();
        TrieNode* current = head;
        stack<TrieNode*> path;
        int len = data.size();
        for (int i = 0; i < len; ++i) {
            switch (data[i]) {
                case '<':
                    path.push(current);
                    break;
                case '>':
                    path.pop();
                    break;
                default:
                    current = new TrieNode();
                    path.top()->children[data[i]] = current;
            }
        }
        return head;
    }
};
