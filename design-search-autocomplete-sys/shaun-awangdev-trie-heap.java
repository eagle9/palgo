/*https://github.com/awangdev/LintCode/blob/master/Java/Design%20Search%20Autocomplete%20System.java
//shaun read and understand the idea, details to be studied
//awangdev with trie and priority queue
//runtime 197ms, faster than 93%, mem less than 87%

cutting: think requirements and storage data structure
store init sentences and times into a trie
store completed sentences (end with #) into the trie

trie node:  children hashmap from char to trie node, bool isEnd, also hashmap freq to store all sentences that start with the prefix and their times. 
once we have the sentence data store and update this way, for each input string, we can get find the corresponding trie node, and get all senteces-times directly, then use a minHeap (keep size <= k) to get top k hot sentences quickly

*/
class AutocompleteSystem {
    class TrieNode {
        public boolean isEnd; //a sentence ended at this node
        public Map<String, Integer> freq; //all sentences that start with the prefix, and their count, already stored in the trie node
        public Map<Character, TrieNode> children; // Map is more applicable to all chars, not limited to 256 ASCII, you can use array too
        public TrieNode() {
            this.freq = new HashMap<>();
            this.children = new HashMap<>();
        }
    }
    class Pair {
        String s;
        int count;
        public Pair(String s, int count) {
            this.s = s;
            this.count = count;
        }
    }
    TrieNode root, curr;
    StringBuffer sb;
    public AutocompleteSystem(String[] sentences, int[] times) {
        if (sentences == null || times == null || sentences.length != times.length) return;
        reset();
        root = new TrieNode();
        for (int i = 0; i < times.length; i++) {
            insert(sentences[i], times[i]);
        }
    }
    
    public List<String> input(char c) {
        List<String> rst = new ArrayList<>();
        if (curr == null) curr = root;
        if (c == '#') { // save sentence and reset state
            insert(sb.toString(), 1);
            reset();
            return rst;
        }
        
        // Update global variable (curr TrieNode and string buffer); or append new character if not exist.
        sb.append(c);
        curr.children.putIfAbsent(c, new TrieNode());
		//current TrieNode that corresponds to sentence input up to c
        curr = curr.children.get(c);

        // find top k=3 hot sentences in trie that starts with current input
        rst.addAll(findTopK(curr, 3));
        
        return rst;
    }
    
    private List<String> findTopK(TrieNode node, int k) {
        List<String> rst = new ArrayList<>();
        if (node.freq.isEmpty()) return rst;
		//use minHeap, min at the top, top k will remain in the heap
        PriorityQueue<Pair> queue = new PriorityQueue<>(
            (a, b) -> a.count == b.count ? b.s.compareTo(a.s) : a.count - b.count);
        for (Map.Entry<String, Integer> entry : node.freq.entrySet()) {
            if (queue.size() < k || entry.getValue() >= queue.peek().count) {
                queue.offer(new Pair(entry.getKey(), entry.getValue()));
            }
            if (queue.size() > k) queue.poll();
        }
        
        //convert the minHeap to list
        while (!queue.isEmpty()) {
            rst.add(0, queue.poll().s);
        }
        
        return rst;
    }
    
    private void reset() {
        curr = null;
        sb = new StringBuffer();
    }
    
    private void insert(String sentence, int count) {
        if (sentence == null || sentence.length() == 0) return;
        TrieNode node = root;
		//for all prefix of the sentence, track all sentences that start with the prefix, with freq HashMap<String,Integer> 
        for (char c : sentence.toCharArray()) {
            node.children.putIfAbsent(c, new TrieNode());
            node = node.children.get(c);
            node.freq.put(sentence, node.freq.getOrDefault(sentence, 0) + count);
        }
        node.isEnd = true; // sentence ended at this end, can set word to node as well, if needed
    }
}


/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * List<String> param_1 = obj.input(c);
 */
