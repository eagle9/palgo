//shaun code in java from gy's c++ code
//accepted after fix 2 bugs with the recursive searchWord function
//runtime 76ms, faster than 85%, mem less than 100%
    class TrieNode {
        TrieNode [] children; //public,  default all works, private not working
        boolean isWord;
        public TrieNode() {
            isWord = false;
            children = new TrieNode[26];
        }
    }
class WordDictionary {
    /*
    default access modifier are accessible only within the same package.
    class TrieNode {
        TrieNode [] children; //public,  default, private all works, since it is inner class
        public TrieNode() {
            isWord = false;
            children = new TrieNode[26];
        }
    }
    */

    private TrieNode root;
    /** Initialize your data structure here. */
    public WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        TrieNode node = root;
        for (char ch: word.toCharArray()) {
            if (node.children[ch - 'a'] == null) node.children[ch - 'a'] = new TrieNode();
            node = node.children[ch - 'a'];
        }
        node.isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return searchWord(root, word, 0);
    }
    private boolean searchWord(TrieNode node, String word, int i) {
        
        if (node == null) return false; //miss this is bug, and put this first, before access node.isWord
        if (i == word.length()) {  //recur exit 
            return node.isWord;
        }
        char ch = word.charAt(i);
        if (ch == '.') { //try all children
            for (TrieNode child: node.children) {
                if (child != null && searchWord(child, word, i+1)) return true; 
            }
            //tried all children and not found, return false
            return false;
        }
        //ch != '.'
        TrieNode child = node.children[ch - 'a'];
        return searchWord(child, word, i+1);
            
        
    }
    public static void main(String [] args) {
    	WordDictionary dict = new WordDictionary();
    	dict.addWord("bad");
    	dict.addWord("dad");
    	dict.addWord("mad");
    	System.out.println("search pad " + dict.search("pad") +  " expected false");
    	System.out.println("search bad " + dict.search("bad") + " expected true");
    	System.out.println("search .ad " + dict.search(".ad") + " expected true");
    	System.out.println("search b.. "  + dict.search("b..") + " expected true");
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
