//Same idea as the offical approach.
//Use a HashMap to keep track of pattern mappings, and DFS with purning to solve it.
//Your submission beats 93.00% Submissions!
public class Solution {
    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    public boolean wordPatternMatch(String pattern, String str) {
        Map<Character, String> map = new HashMap<>();
        return dfs(pattern, str, map);
    }
    
    private boolean dfs(String ptn, String s, Map<Character, String> map) {
        if (ptn.length() == 0 && s.length() == 0) {
            return true;
        }
        
        if (ptn.length() == 0 || s.length() == 0) {
            return false;
        }
        
        if (map.containsKey(ptn.charAt(0))) {
            String prefix = map.get(ptn.charAt(0));
            if (!s.startsWith(prefix)) {
                return false;
            }
            return dfs(ptn.substring(1), s.substring(prefix.length()), map);
        }
        
        for (int i = 1; i <= s.length(); i++) {
            String prefix = s.substring(0, i);
            if (map.values().contains(prefix)) {
                continue;
            }
            map.put(ptn.charAt(0), prefix);
            if (dfs(ptn.substring(1), s.substring(prefix.length()), map)) {
                return true;
            }
            map.remove(ptn.charAt(0));
        }
        return false;
    }
}
