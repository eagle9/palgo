class Solution {
    //grandyang's idea, similar to isomorphic strings, 
    //key point Integer a, b,   you can not use a==b, use equals or compareTo, or intValue
    //beats 39%
    public boolean wordPattern(String pattern, String str) {
        char [] chars = pattern.toCharArray();
        String [] words = str.split(" ");
        
        int m = chars.length;
        int n = words.length;
        if (m != n) return false;
        System.out.println("n=" + n + ",m=" + m);
        //Map<Character, Integer> map1 = new HashMap<>();
        int [] map1 = new int[256];
        Map<String, Integer> map2 = new HashMap<>();
        for (int i = 0; i < n; i++) {
            char c = chars[i];
            String s = words[i];
            //map1.put(c,0);
            
            map2.put(s,0);
        }
        
        for (int i = 0; i < n; i++) {
            char c = chars[i];
            String s = words[i];
            
            //if (map1.get(c) != map2.get(s))  //wont work
            //if (map1.get(c).compareTo(map2.get(s)) != 0)  okay
            //if (!map1.get(c).equals(map2.get(s)))  okay
            //if (map1.get(c).intValue() != map2.get(s).intValue()) okay
            if (map1[c] != map2.get(s).intValue())
                return false;
            
            //map1.put(c,i+1);
            map1[c] = i+1;
            map2.put(s,i+1);
        }
        return true;
        
    }
}
