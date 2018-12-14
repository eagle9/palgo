class Solution {
    //grandyang idea, beats 97%, great idea that leads to clean and natural code
    //use two size 256 arrays for maps
    public boolean isIsomorphic000(String s, String t) {
        int len = s.length();
        if (len != t.length()) return false;
        
        //key is ascii chars
        int [] map1 = new int[256]; //java init with 0, boolean with false
        int [] map2 = new int[256];
        
        for (int i = 0; i < len; i++) {
            char a = s.charAt(i), b = t.charAt(i);
            //same position char mapped same value, diff from init value
            //otherwise return false
            if (map1[(int)a] != map2[(int)b]) return false;
            map1[(int)a] = i+1;
            map2[(int)b] = i+1;
        }
        return true;
    }
    //what if we do no explicit conversion from char to int???
    //java is okay with using char as int
    public boolean isIsomorphic(String s, String t) {
        int len = s.length();
        if (len != t.length()) return false;
        
        //key is ascii chars
        int [] map1 = new int[256]; //java init with 0, boolean with false
        int [] map2 = new int[256];
        
        for (int i = 0; i < len; i++) {
            char a = s.charAt(i), b = t.charAt(i);
            //same position char mapped same value, diff from init value
            //otherwise return false
            if (map1[a] != map2[b]) return false;
            map1[a] = i+1;
            map2[b] = i+1;
        }
        return true;
    }
}
