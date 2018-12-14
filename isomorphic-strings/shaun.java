class Solution {
    //shaun's idea, only use map1, wrong answer, was not to the point of 1on1 mapping
    //user map1 and map2, beats 16%
	//key is 1 to 1 mapping, using 1 map won't cut it
	//key point2, key are chars, you can use array rather than full blown hashmap
    public boolean isIsomorphic(String s, String t) {
        Map<Character,Character> map1 = new HashMap<>();
        Map<Character,Character> map2 = new HashMap<>();
        int len = s.length();
        if (len != t.length()) return false;
        
        //s = ab, b = aa
        // a:a -  b:a
        // a:a -  a:b 
        for (int i = 0; i < len; i++) {
            char a = s.charAt(i);
            char b = t.charAt(i);
            if (!map1.containsKey(a)) {
                map1.put(a,b);
            }else {
                if (b != map1.get(a)) return false;
            }
            if (!map2.containsKey(b)) {
                map2.put(b,a);
            }else {
                if (a != map2.get(b)) return false;
            }
            
        }
        //passed all tests
        return true;
    }
}
