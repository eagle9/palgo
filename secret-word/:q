//shaun's own code, wrong answer first try
//another idea tried, modified twice with test cases
//accepted, beats 49%
/*
does not pass
"aaaasds"
"gkg"

"aaaaa"
"djfjdskfjdkjf"

"abcabcd"
"xyzxyz"

*/

public class Solution {
    /**
     * @param s: the long string
     * @param word: the secrect word
     * @return: whether a substring exists in the string can be transformed by the above encoding rule
     */
     
    public String getAns(String s, String word) {
        if (s == null)
            return "no";
        int len = word.length();
        //for (int i = 0; i < s.length()-len; i++) { //wont pass
        for (int i = 0; i <= s.length()-len; i++) {
            String sub = s.substring(i,i+len);
            //return getAns2(sub,word); wrong answer
            if (check(sub,word))
                return "yes";
            else
                continue;
        }
        return "no";
    }
    
    //check equal len s and word
    private boolean check(String s, String word) {
        
        int len = s.length();
        
        Map<Character,Character> cmap12 = new HashMap<>();
        Map<Character,Character> cmap21 = new HashMap<>();
        for (int i = 0; i < len; i++) {
            char c1 = s.charAt(i);
            char c2 = word.charAt(i);
            if ( !cmap12.containsKey(c1)) {
                cmap12.put(c1,c2);
            }else {
                char prevChar = cmap12.get(c1);
                if (prevChar != c2)
                    return false;
            }
            
            if ( !cmap21.containsKey(c2)) {
                cmap21.put(c2,c1);
            }else {
                char prevChar = cmap21.get(c2);
                if (prevChar != c1)
                    return false;
            }
            
            
        }
        return true;
    }
    
 
}
