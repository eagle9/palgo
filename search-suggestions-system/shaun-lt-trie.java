//lt solution with trie and dfs, shaun understood
// Custom class Trie with function to get 3 words starting with given prefix
//shaun changed children from List to array
class Trie {

    // Node definition of a trie
    class Node {
        boolean isWord = false;//attribute
        Node [] children = new Node[26]; //link
    };
    Node Root, curr;
    List<String> resultBuffer;

    // Runs a DFS on trie starting with given prefix and adds all the words in the resultBuffer, limiting result size to 3
    void dfsWithPrefix(Node curr, String word) {
        if (resultBuffer.size() == 3) return; //recur exit, otherwise explore all
        if (curr.isWord)
            resultBuffer.add(word);

        // Run DFS on all possible paths, look for all words started with word
        for (char c = 'a'; c <= 'z'; c++) {
            Node child = curr.children[c - 'a'];
            if ( child != null) {
                dfsWithPrefix(child, word + c);
            }
        }
            
    }
    Trie() {
        Root = new Node();
    }

    // Inserts the string in trie.
    void insert(String s) {

        // Points curr to the root of trie.
        curr = Root;
        for (char c : s.toCharArray()) {
            if ( curr.children[c - 'a'] == null)
                curr.children[c - 'a'] = new Node();
            curr = curr.children[c - 'a'];
        }

        // Mark this node as a completed word.
        curr.isWord = true;
    }
    List<String> getWordsStartingWith(String prefix) {
        curr = Root;
        resultBuffer = new ArrayList<String>();
        // Move curr to the end of prefix in its trie representation.
        for (char c : prefix.toCharArray()) {
            if (curr.children[c - 'a'] == null)
                return resultBuffer;
            curr = curr.children[c - 'a'];
        }
        //curr is the trie node corresponding to prefix
        dfsWithPrefix(curr, prefix);
        return resultBuffer;
    }
};
class Solution {
    List<List<String>> suggestedProducts(String[] products,
                                         String searchWord) {
        Trie trie = new Trie();
        List<List<String>> result = new ArrayList<>();
        // Add all words to trie.
        for (String w : products)
            trie.insert(w);
        String prefix = new String();
        for (char c : searchWord.toCharArray()) {
            prefix += c;
            result.add(trie.getWordsStartingWith(prefix));
        }
        return result;
    }
};
