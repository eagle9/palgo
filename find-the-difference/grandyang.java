public class Solution {
    
    //grandyang with hashmap, beats 58%, c++ and java quite different
    public char findTheDifference(String s, String t) {
        // Write your code here
        HashMap<Character,Integer> m = new HashMap<>();
        for (char c: t.toCharArray()) {
            if (!m.containsKey(c))
                m.put(c,1);
            else {
                int i = m.get(c);
                i++;
                m.put(c,i);
            }
        }
        char res = '0';
        for (char c: s.toCharArray()) {
            
            int i = m.get(c);
            i--;
            
            m.put(c,i);
        }
        for (char c : m.keySet()) {
            int i = m.get(c);
            if (i >0)
                res = c; 
        }
        return res;
    }
    
    /**
     * @param s: a string
     * @param t: a string
     * @return: the letter that was added in t
     */
    //grandyang with bit manipulation, beats 100%
    public char findTheDifference1(String s, String t) {
        // Write your code here
        char res = 0;
        for (char c: s.toCharArray())
            res ^= c;
        for (char c: t.toCharArray())
            res ^= c;
        return res;
    }
    //grandyang using addition and subtraction, wrong answer
    public char findTheDifference2(String s, String t) {
        // Write your code here
        char res = 0;
        for (char c: s.toCharArray())
            res += c;
        for (char c: t.toCharArray())
            res -= c;
        return res;
    }
}

