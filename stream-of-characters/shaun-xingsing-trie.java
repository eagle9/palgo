/*
https://xingxingpark.com/Leetcode-1032-Stream-of-Characters/

runtime 308ms, faster than 67%, mem less than 58%
解题思路
题目要求输入一个字符串数组作为字典， 然后不断查询字符，如果最近的k个字符构成一个完整的字典单词的话，返回true，否则返回false。

这个题目可以使用字典树(Trie)求解。 对每个字符查询，当返回true时，一定是一个完整的单词。值得注意的技巧是，反向查询可以节省很多开销。因为正向查询的话要保存很多上次访问到的节点，因为开始的地方可能会很多，所以这个Trie可以反过来建， 这样每次查询的时候都可以从最后面开始查询起。

建Trie的过程是对每个单词逆序插入Trie， 从最后一个字符开始到第一个字符插入建立Trie。
查询的时候，因为接受的是一个stream，我们需要的stream的长度不应该超过Trie的最大深度。这样保证了我们的空间复杂度不会过大。

每次查询从stream的最后一个字符开始向前查询，查到一个完整的单词就返回true，否则就返回false。
*/

class TrieNode {
    boolean isWord;
    TrieNode [] child;
    TrieNode() {
        isWord = false;
        child = new TrieNode[26];
    }
};
class Trie {
    TrieNode root;
    
    Trie() {
        root = new TrieNode();
    }
    //xyz ==> z y x
    void insert(String word) {
        TrieNode cur = root;
        //from tail
        for (int i = word.length()-1; i >=0; i--) {
            int pos = word.charAt(i) - 'a';
            if (cur.child[pos] == null) {
                cur.child[pos] = new TrieNode();
            }
            cur = cur.child[pos]; 
        }
        cur.isWord = true;
    }
  
    boolean findWord(String word) {
        TrieNode cur = root;
        for (int i = word.length()-1; i >=0; i--) {
            int pos = word.charAt(i) - 'a';
            cur = cur.child[pos];
            if (cur == null) {
                return false;
            }
            if (cur.isWord) { //return true can happen before finishing all chars, this is special treatment for this problem
                return true;
            }
        }
        return false;
    }
    
};

class StreamChecker {
    StringBuilder stream = new StringBuilder();
    Trie trie = new Trie();
    int maxLen = 0;
    public StreamChecker(String[] words) {
        for (String word : words) {
            trie.insert(word);
            maxLen = Math.max(maxLen, word.length());
        }
    }
    
    public boolean query(char letter) {
        stream.append(letter);
        
        if (stream.length() > maxLen) {
            //stream.setLength(0);
            stream.deleteCharAt(0);
        }
        return trie.findWord(stream.toString());

    }
}


/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

