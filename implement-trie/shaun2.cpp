/*
Runtime: 88 ms, faster than 100.00% of C++ online submissions for Implement Trie (Prefix Tree).
Memory Usage: 45 MB, less than 100.00% of C++ online submissions for Implement Trie (Prefix Tree).
shaun coded the cpp from memory, based on grandyang idea
*/
class TrieNode {
public:
    TrieNode * child[26];
    //vector<TrieNode*> child(26);  //can i use vector?? no use of vector!!!! because we want fixed size for TrieNode object
    bool isWord;
    //shaun didn't come up with the following constructor on first try
    //shaun missed p=p->child[i] in search and startWith
    TrieNode(): isWord(false) {
        //child.reserve(26);
        for (auto & a : child) a = NULL;
    }
};
class Trie {
private:
    TrieNode * root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    /*
    Choose auto x when you want to work with copies.
Choose auto &x when you want to work with original items and may modify them.
Choose auto const &x when you want to work with original items and will not modify them.
    */
    /** Inserts a word into the trie. */
    void insert(string word) {
        //word from left to right, trie from root to leaf
        TrieNode * p = root;
        //for (auto c: word) works too, with value, you can not change c
        for (auto & c: word) {
            int i = c - 'a';
            //letter to child node
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        //done with all letters in the word
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * p = root;
        for (auto & c: word) {
            int i = c - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * p = root;
        for (auto & c: prefix) {
            int i = c - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        //finish all letter in prefix, not met any NULL
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
