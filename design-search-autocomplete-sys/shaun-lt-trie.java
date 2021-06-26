/*lt idea trie to store all words completed, and use single link list to store 
runtime  239ms, faster than 41%, mem less than 100%
cutting: use trie to store all sentences (a-z, space) and their times info
the problem asks for top 3 hot sentences that start with input string
nuturally use trie to store sentence and its times info, suitable to find all sentences that start with a given input string. to simplify getting the sentences that start with input,  use a list of (sentence, times) to store the immediate results, then sort  it and take the top3 if list.size > 3

shaun fully understand
design problem: read problem description, catch all requirements, think of data storage, choose suitable data structure, break down the main services/functions into smaller services/functions
*/
public class AutocompleteSystem {
    
    //copy of TrieNode info, store both sentence and times info
    class Node {
        Node(String st, int t) {
            sentence = st;
            times = t;
        }
        String sentence;
        int times;
    }
    //TrieNode, to store sentences completed, each sentence consists of letters and space
    // info is times -- number of times the corresponding sentence completed
    class Trie {
        int times;
        Trie[] branches = new Trie[27];
    }
    
    //util function that converts char to TrieNode child index
    public int int_(char c) {
        return c == ' ' ? 26 : c - 'a';
    }
    //store a sentence and times info into Trie
    public void insert(Trie t, String s, int times) {
        //iterate the string char by char
        for (int i = 0; i < s.length(); i++) {
            if (t.branches[int_(s.charAt(i))] == null)
                t.branches[int_(s.charAt(i))] = new Trie();
            //t goes down from root to leaf
            t = t.branches[int_(s.charAt(i))];
        }
        t.times += times;
    }
    
    //give a sentence,  find all sentences in the trie that starts with the given sentence as prefix 
    public List < Node > lookup(Trie t, String s) {
        List < Node > list = new ArrayList < > ();
        for (int i = 0; i < s.length(); i++) {
            if (t.branches[int_(s.charAt(i))] == null)
                return new ArrayList < Node > ();
            t = t.branches[int_(s.charAt(i))];
        }
        //trie node t corresponds to sentence s
        //now traverse trie from t, store all <sentence, times> into list
        //advantage with trie, info compact, good for startwith api
        traverse(s, t, list);
        return list;
    }
    
    //traverse trie from node t, corresponding to sentence s
    //  store all sentence-times pair into a new list, that all start with s
    // note: 27 children a-z and space char
    // dfs, sync sentence with trie node, no recursion when trie node is null
    public void traverse(String s, Trie t, List < Node > list) {
        if (t.times > 0)
            list.add(new Node(s, t.times));
        for (char i = 'a'; i <= 'z'; i++) {
            if (t.branches[i - 'a'] != null)
                traverse(s + i, t.branches[i - 'a'], list);
        }
        if (t.branches[26] != null)
            traverse(s + ' ', t.branches[26], list);
    }
    //track the root of trie
    Trie root;
    
    //specified in problem statement
    //sentences come from constructor and input end with # char
    public AutocompleteSystem(String[] sentences, int[] times) {
        root = new Trie();
        for (int i = 0; i < sentences.length; i++) {
            insert(root, sentences[i], times[i]);
        }
    }
    String cur_sent = "";
    //input api required in the problem statement
    //char a-z, space char and # (mark end of a historical sentence)
    public List < String > input(char c) {
        List < String > res = new ArrayList < > ();
        if (c == '#') { 
            insert(root, cur_sent, 1); //end of a historical sentence
            cur_sent = ""; //reset search
        } else {
            cur_sent += c;
            //lookup return all (sentence, times) that startwith cur_sent
            List < Node > list = lookup(root, cur_sent);
            Collections.sort(list, (a, b) -> a.times == b.times ? a.sentence.compareTo(b.sentence) : b.times - a.times);
            for (int i = 0; i < Math.min(3, list.size()); i++)
                res.add(list.get(i).sentence);
        }
        return res;
    }
}       


/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * List<String> param_1 = obj.input(c);
 */
