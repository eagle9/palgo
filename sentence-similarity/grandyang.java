class Solution {
    //grandyang idea, beats 99.54%, shaun own java code from the idea
    public boolean areSentencesSimilar(String[] words1, String[] words2, String[][] pairs) {
        if (words1.length != words2.length) return false;
        
        Map<String,Set<String>> m = new HashMap<>();
        for (int row = 0; row < pairs.length; row++) {
            String first = pairs[row][0];
            String second= pairs[row][1];
            if (!m.containsKey(first))
                m.put(first, new HashSet<>());
            m.get(first).add(second);
            
        }
            
        for (int i = 0; i < words1.length; i++) {
            String word1 = words1[i];
            String word2 = words2[i];
            if (word1.equals(word2)) continue;
            Set<String> set1 = m.get(word1);
            Set<String> set2 = m.get(word2);
            if ((set1 == null ||!set1.contains(word2)) && (set2 == null || !set2.contains(word1)))
                return false;
            
        }
        return true;
    }
}
