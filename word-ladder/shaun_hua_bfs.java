//hua bfs idea, shaun deep read and modified.
//runtime 208ms, faster than 46%
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        //convert wordlist to wordset for quick word in dict check
        Set<String> dict = new HashSet<>();
        dict.addAll(wordList);
        
        //problem statement, endWord not in dict, return 0, can not transform
        if (!dict.contains(endWord)) return 0; 
        // queue for bfs
        Queue<String> q = new LinkedList<>();
        q.offer(beginWord);
        int step = 0;
        int len = beginWord.length();
        Set<String> seen = new HashSet<>();
        seen.add(beginWord);
        while (!q.isEmpty()) {
            ++step;
            //in order for step var to be level, you have to deq all elements
            int n = q.size();
            for (int j = 0; j < n; j++) {
                char[] w = q.poll().toCharArray();
                //for each letter w[i] of the word, change it to different letter
                for (int i = 0; i < len; i++) {                
                    char ch = w[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (w[i] == c) continue;
                        
                        char [] nw = Arrays.copyOf(w, w.length);
                        nw[i] = c;
                        String newWord = new String(nw);
                        if (seen.contains(newWord)) continue;
                        if (newWord.equals(endWord)) return step + 1;
                        // Not in dict, skip it
                        if (!dict.contains(newWord)) continue;
                        // w seen before, Remove new word from dict
                        //dict.erase(nw);
                        // Add new word into queue
                        q.offer(newWord); 
                        seen.add(newWord);
                    }
                }
            }
        }
        return 0;
    }
}

