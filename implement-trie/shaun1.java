//runtime 74ms, faster than 87%, mem less than 33%
//cutting: trie is tree with 26 children, to store some kind of key value pair
// key is string, value is the string is a word seen or not
class TrieNode {
    // Initialize your data structure here.
    TrieNode [] child = new TrieNode[26];
    boolean isWord = false;
    public TrieNode() {
        //isWord = false;
        //for (TrieNode ch : child) ch = null;
    }
};
class Trie {
    private TrieNode root = null;
    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode p = root;
        for (char c : word.toCharArray()) {
            int i = c - 'a';
            if (p.child[i] == null) p.child[i] = new TrieNode();
            p = p.child[i];
        }
        p.isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode p = root;
        for (char c : word.toCharArray()) {
            int i = c - 'a';
            if (p.child[i] == null) return false;
            p = p.child[i];
        }
        return p.isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode p = root;
        for (char c : prefix.toCharArray()) {
            int i = c - 'a';
            if (p.child[i] == null) return false;
            p = p.child[i];
        }
        return true;
    }
}




/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
