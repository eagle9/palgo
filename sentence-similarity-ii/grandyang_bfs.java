class Solution {
    //grandyang bfs idea, shaun java code from the idea, beats 21%
    public boolean areSentencesSimilarTwo(String[] words1, String[] words2, String[][] pairs) {
        //obviously not similar when length are not equal
        if (words1.length != words2.length) return false;
        
        //edge represents similarity between words
        // it is symmetric
        Map<String, Set<String>> m = new HashMap<>();
        for (int row = 0; row < pairs.length; row++) {
            String first = pairs[row][0];
            String second = pairs[row][1];
            if (!m.containsKey(first))
                m.put(first,new HashSet<>());
            m.get(first).add(second);
            if (!m.containsKey(second))
                m.put(second,new HashSet<>());
            m.get(second).add(first);
        }
        
        //check each word1 if it can reach word2 
        for (int i = 0; i < words1.length; i++) {
            if (words1[i].equals(words2[i]))
                continue;
            
            boolean found = false;
            //can we go from w1 to w2 via edges by m?
            Set<String> visited = new HashSet<>();
            Queue<String> q = new LinkedList<>();
            q.offer(words1[i]);
            while (!q.isEmpty() && !found) {
                String word = q.poll();
                Set<String> nset = m.get(word);
                
                if (nset == null) break;
                if (nset.contains(words2[i])) {
                    found = true;
                    break;
                }
                visited.add(word);
                
                for (String next: nset) {
                    //check each neighbor words
                    
                    if (!visited.contains(next)) {
                        q.offer(next);
                        
                    }
                }
            }
            if (!found) return false;
            
        }
        return true;
    }
}
