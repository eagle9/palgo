class Solution {
    
    //shaun original idea and code using two maps for 1on1 , beats 39%
    public boolean wordPattern(String pattern, String str) {
        char [] chars = pattern.toCharArray();
        String [] words = str.split(" ");
        
        
        int m = chars.length;
        int n = words.length;
        if (m != n) return false;
        System.out.println( m + " " + n);
        Map<Character, String> map1 = new HashMap<>();
        Map<String, Character> map2 = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            Character c = chars[i];
            String s = words[i];
            if (!map1.containsKey(c)) map1.put(c,s);
            else {
                if (!s.equals( map1.get(c))) return false;
            }
            if (!map2.containsKey(s)) map2.put(s,c);
            else {
                if (!c.equals( map2.get(s))) return false;
            }
            
        }
        
        //passed all tests
        return true;
        
    }
}
