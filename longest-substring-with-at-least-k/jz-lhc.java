//jz linghuchong, idea check my c++ code, accepted and fast solution
class Solution {
    public int longestSubstring(String s, int k) {
        HashMap<Character, Integer> counter = getCharCounter(s);
        
        int left = 0;
        int longest = 0;
        for (int i = 0; i < s.length(); i++) {
            if (counter.get(s.charAt(i)) < k) {
                int sub_longest = longestSubstring(s.substring(left, i), k);
                longest = Math.max(longest, sub_longest);
                left = i + 1;
            }
        }
        
        if (left == 0) {
            return s.length();
        }
        
        int sub_longest = longestSubstring(s.substring(left, s.length()), k);
        longest = Math.max(longest, sub_longest);
        
        return longest;
    }
    
    private HashMap<Character, Integer> getCharCounter(String s) {
        HashMap<Character, Integer> counter = new HashMap<>();
        
        for (int i = 0; i < s.length(); i++) {
            Character c = s.charAt(i);
            Integer val = counter.getOrDefault(c, 0);
            counter.put(c, val + 1);
        }
        
        return counter;
    }
}
