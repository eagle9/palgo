//wrong answer
class ValidWordAbbr {

    public ValidWordAbbr(String[] dictionary) {
        for (String word: dictionary) {
            if (word == null) continue;
            int n = word.length();
            String ab = word;
            //no abr when n <= 2
            if (n > 2) {
                ab = word.substring(0,1) + String.valueOf(n-2) + word.substring(n-1,n);
            }
            if (!m.containsKey(ab)) {
                Set<String> s = new HashSet<>();
                s.add(ab);
                m.put(ab,s);
            }else {
                Set<String> s = m.get(ab);
                s.add(ab);
            }
        }
    }
    
    public boolean isUnique(String word) {
        int n = word.length();
        String ab = word;
        if (n > 2) {
            ab = word.substring(0,1) + String.valueOf(n-2) + word.substring(n-1,n);
        }
        if (m.containsKey(ab)) {
            Set<String> s = m.get(ab);
            return s.contains(word) && s.size() == 1;
        }
        return true;
    }
    
    private Map<String,Set<String>> m = new HashMap<>();
}

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * boolean param_1 = obj.isUnique(word);
 */
