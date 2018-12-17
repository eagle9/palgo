//grandyang idea shaun java code, first try TLE
//after use StringBuilder to generate the final result, beats 88%
public class Solution {

    public String licenseKeyFormatting(String S, int K) {
        
        //cnt is the count of chars that is not -
        int cnt = 0, n = S.length();
        List<Character> res = new ArrayList<>();
        //List<Character> res = new LinkedList<>(); //using LinkedList, TLE
        //from tail to head
        for (int i = n - 1; i >= 0; --i) {
            char c = S.charAt(i);
            
            // - will be skipped
            if (c == '-') continue;
            //convert lower case to upper
            if (c >= 'a' && c <= 'z') 
                //c = Character.toUpperCase(c);
                c -= 32;
            
            res.add(c);
            
            //processed one meaningful char
            //++cnt, if cnt is multiple of K, add -
            if (++cnt % K == 0) res.add('-');
        }
        
        //when you call remove, linkedlist will have problem
        if (res.size() > 0 && res.get(res.size()-1) == '-') res.remove(res.size()-1);
        
        StringBuilder sb = new StringBuilder();
        for (int i = res.size()-1; i >=0; i--) {
            sb.append(res.get(i));
            //you can not use String s, s+= c
        }
        return sb.toString();
    }
};
