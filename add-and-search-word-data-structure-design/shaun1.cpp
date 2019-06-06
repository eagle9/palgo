/*
Runtime: 96 ms, faster than 94.13% of C++ online submissions for Add and Search Word - Data structure design.
Memory Usage: 44.5 MB, less than 70.44% of C++ online submissions for Add and Search Word - Data structure design.
grandyang idea of trie use and dfs, shaun has read and understood
*/
class WordDictionary {
public:
    struct TrieNode {
    public:
        TrieNode *child[26]; //pointer to all 26 children
        bool isWord; 
        TrieNode() : isWord(false) {
            for (auto &a : child) a = NULL; //set all child pointers to NULL
        }
    };
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure. start from root and for each char
    void addWord(string word) {
        TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        //done with all chars, end char's trienode isWord = true
        p->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(word, root, 0);
    }
    
    //因为这道题里面'.'可以代替任意字符，所以一旦有了'.'，就需要查找所有的子树，只要有一个返回true，整个search函数就返回true，典型的DFS的问题
    bool searchWord(string &word, TrieNode *p, int i) {
        if (i == word.size()) return p->isWord; //dfs recur exit
        if (word[i] == '.') {
            //. matches any char
            for (auto &a : p->child) {
                if (a && searchWord(word, a, i + 1)) return true;
            }
            return false;
        } else {
            TrieNode* child = p->child[word[i] - 'a'];
            return child  && searchWord(word, child, i + 1);
        }
    }
    
private:
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
