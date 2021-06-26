//grandyang idea, two pointers with hashtable, shaun java code, 
//runtime 13ms, faster than 39%
//map from char to count
class Solution1 {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        int res = 0, left = 0;
        Map<Character, Integer> m = new HashMap<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            //++m[s[i]];
            char c = s.charAt(i);
            m.putIfAbsent(c,0);
            m.put(c,m.get(c)+1);
            
            while (m.size() > 2) {
                c = s.charAt(left);
                if (m.get(c) != null) {
                    m.put(c, m.get(c)-1);
                    if (m.get(c) == 0) m.remove(c);
                }
                
                ++left;
            }
            //m.size == 2 now, from left to i
            res = Math.max(res, i - left + 1);
        }
        return res;
    }
}

//similar idea, grandyang 2, 
//runtime 9ms, faster than 72%
//two pointers, but hash table from char to its index, cleaner and quicker
//similar idea as at most two case, replace 2 with k
class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int res = 0, left = 0;
        Map<Character, Integer> m = new HashMap<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            //++m[s[i]];
            char c = s.charAt(i);
            m.put(c,i);
            
            //from left to i, more than 2 chars, remove the left char
            while (m.size() > k) {
                c = s.charAt(left);
                if (m.get(c) == left) {
                    m.remove(c);
                }
                
                ++left;
            }
            //m.size == 2 now, from left to i
            res = Math.max(res, i - left + 1);
        }
        return res;
    }
}
