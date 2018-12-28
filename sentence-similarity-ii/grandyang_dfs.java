class Solution {
    //grandyang dfs idea, shaun java code from the idea, beats 18%
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
        //Set<String> visited = new HashSet<>();  put here ==> wrong answer
        for (int i = 0; i < words1.length; i++) {
            Set<String> visited = new HashSet<>();
            String word1 = words1[i];
            String word2 = words2[i];
            if (!helper(m,word1, word2, visited))
                return false;
        }
        return true;
       
    }
    
    boolean helper(Map<String,Set<String>> m, String cur, String target, Set<String> visited) {
        if (cur.equals(target))
            return true;
        visited.add(cur);
        Set<String> nset = m.get(cur);
        if (nset == null)
            return false;
        for (String next: nset) {
            if (!visited.contains(next)) {
                if (helper(m, next, target, visited))
                    return true;
            }
        }
        return false;
    }
}
