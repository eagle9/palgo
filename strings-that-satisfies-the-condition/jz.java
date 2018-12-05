//jz, beats 26%
//key is comes up with satisfy function, with two pointers
public class Solution {
    /**
     * @param target: the target string
     * @param s: 
     * @return: output all strings containing target  in s
     */
    public String[] getAns(String target, String[] s) {
        boolean [] take = new boolean [s.length];
        int count = 0;
        
        char [] ta = target.toCharArray();

        for (int i = 0; i < s.length; i++) {
            if (satisfy(s[i].toCharArray(), ta)) {
                count ++;
                take[i] = true;
            }
            else {
                take [i] = false;
            }
        }
        
        String [] result = new String [count];
        int idx = 0;
        for (int i = 0; i < s.length; i++) {
            if (take[i]) {
                result[idx] = s[i];
                idx++;
            }
        }
        return result;
    }
    
    private boolean satisfy (char[] source, char[] target) {
        
        int s = 0;
        int t = 0;
        
        //two pointer
        while (s < source.length && t < target.length) {
            //matched, move both pointers
            if (source[s] == target[t]) {
                s++;
                t++;
            }
            else { //no match, move pointer in source
                s++;
            }
        }
        
        //return ?   last element of target compared? t == target.length???? 
        return t == target.length;
    }

}
