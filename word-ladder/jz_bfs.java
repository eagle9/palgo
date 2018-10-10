//jz bfs beats 88.00%
//bfs is very natural solution to this problem
public class Solution {
    public int ladderLength(String start, String end, Set<String> dict) {
        if (dict == null) {
            return 0;
        }
        //if start equals end, return length =1
        if (start.equals(end)) {
            return 1;
        }
        
        dict.add(start);
        dict.add(end);

        HashSet<String> visited = new HashSet<String>();
        Queue<String> queue = new LinkedList<String>();
        //Queue<String> queue = new ArrayDeque<String>();
        queue.offer(start);
        visited.add(start);
        
        int level = 1;
        while(!queue.isEmpty()) {
            level++;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String word = queue.poll();
                for (String nextWord: getNextWords(word, dict)) {
                    if (visited.contains(nextWord)) {
                        continue;
                    }
                    //not yet visited nextWord
                    if (nextWord.equals(end)) {
                        return level;
                    }
                    
                    visited.add(nextWord);
                    queue.offer(nextWord);
                }
            }
        }
        //problem statement: return 0 when no such transformation is found
        return 0;
    }

    // replace character of a string at given index to a given character
    // return a new string
    private String replace(String s, int index, char c) {
        char[] chars = s.toCharArray();
        chars[index] = c;
        return new String(chars);
    }
    
    // get connections with given word.
    // for example, given word = 'hot', dict = {'hot', 'hit', 'hog'}
    // it will return ['hit', 'hog']
    private ArrayList<String> getNextWords(String word, Set<String> dict) {
        ArrayList<String> nextWords = new ArrayList<String>();
        //for (char c = 'a'; c <= 'z'; c++) {
        //    for (int i = 0; i < word.length(); i++) {
        for (int i = 0; i < word.length(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == word.charAt(i)) { //looking for change
                    continue;
                }
                String nextWord = replace(word, i, c);
                if (dict.contains(nextWord)) {
                    nextWords.add(nextWord);
                }
            }
        }
        return nextWords;
    }
}
