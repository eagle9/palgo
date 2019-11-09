//shaun java code from jz dfs backtracking idea
//runtime 36ms, faster than 78%, mem less than 53%
class Solution {
    public boolean wordPatternMatch(String pattern, String str) {
        seenPattern = new HashMap<>();
        seenWord = new HashMap<>();
        return helper(pattern, 0, str, 0);
    }
    private boolean helper(String pattern, int i, String str, int j) {
        if (i == pattern.length() && j == str.length()) return true;
        if (i == pattern.length() || j == str.length()) return false;
        char p = pattern.charAt(i);
        
        if (seenPattern.containsKey(p)) {
            String expectedWord = seenPattern.get(p);
            int jend = j + expectedWord.length();
            
            if (jend <= str.length() && expectedWord.equals(str.substring(j, jend)) ){
                //seen pattern p, found match in str, recur
                return helper(pattern,i+1, str,jend);
            }else { //jend < str.length or !=, no match, decided
                return false;
            }
        }
        //p is new pattern, try all possible words from j
        for (int jend = j+1; jend <= str.length(); jend++) {
            String word = str.substring(j, jend);
            if (seenWord.containsKey(word)) continue; //word already tied to an existing pattern char, skip
            seenPattern.put(p, word);
            seenWord.put(word,p);
            if (helper(pattern, i+1, str, jend)) return true; //only return when match, otherwise keep trying
            seenPattern.remove(p);
            seenWord.remove(word);
            
        }
        //at this point, no match found
        return false;
        
    }
    private Map<Character,String> seenPattern;
    private Map<String,Character> seenWord;
}
