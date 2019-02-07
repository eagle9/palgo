//solution1 grandyang idea with two pointers, simple idea and simple immplementation
class Solution1 {
    public boolean isSubsequence(String s, String t) {
        //empty string can be subsequence of any string
        if (s.length() == 0) return true;
        char [] ss = s.toCharArray();
        char [] tt = t.toCharArray();
        int i = 0, j = 0; 
        //s = "abc", 
        //t = "ahbgdc"
        //for (; i < ss.length, j < tt.length;) {  //shaun first try, nuts!!!!!
        for (; i < ss.length && j < tt.length; ) {
            if (ss[i] == tt[j]) {
                i++;
                j++;
            }else {
                j++;
            }
        }
        return i == ss.length;
    }
}
//shaun's own idea with hashtable, to address the follow up question
//a little bit challenge when i realized that letters in T could be repetitive, but committed to my idea and finish it
//runtime 47ms, faster than 18%
//using hash table no advantage, two pointer is better, O(lenS)
class Solution {
    private Map<Character,List<Integer>> map = null;
    private void init (String t) {
        char [] tt = t.toCharArray();
        map = new HashMap<>();
        for (char c = 'a'; c <= 'z'; c++) {
            map.put(c,new ArrayList<>());
        }
        for (int j = 0; j < tt.length; j++) {
            char c = tt[j];
            map.get(c).add(j);
        }
    }
    public boolean isSubsequence(String s, String t) {
        //empty string can be subsequence of any string
        if (s.length() == 0) return true;
        char [] ss = s.toCharArray();
        init(t);
        
        int pos = 0, prev = 0;
        for (int i = 0; i < ss.length; i++){
            char c = ss[i];
            List<Integer> list = map.get(c);
            if (list.size() == 0) return false;
            if (i == 0) {
                pos = list.get(0);
                continue;
            }else {
                int k = 0;
                for (; k < list.size(); k++) {
                    pos = list.get(k);
                    if (pos > prev) break;
                }
                if (k == list.size()) return false;
                
            }
            prev = pos;
            
        }
        return true;
    }
}

