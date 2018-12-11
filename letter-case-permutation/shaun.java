//beats 100%, grandyang using bitmap
//T = O(P*len), where P is the number of permutations, len is length of string

//shaun code in java, beats only 15%, 40%
class Solution {
    public List<String> letterCasePermutation(String S) {
        List<String> res = new ArrayList<>();
        int n = 0;
        //find the number of letters in S
        char [] chars = S.toCharArray();
        for (char c: chars) {
            if (c > '9')
                n++;
        }
        //number of permutations
        int P = 1 << n;
        
        for (int i = 0; i < P; i++) {
            int j = 0; //number of letters
            //String word = "";
            char [] word = new char[chars.length];
            //for (char c: chars) {
            for (int k =0; k < chars.length; k++) {
                char c = chars[k];
                if (c > '9') {  //is letter
                    //if jth bit is 1, upper case
                    //else lower case
                        
                    if ( ((i >>j) & 1)  == 1) {
                        //word += Character.toUpperCase(c);
                        word[k] = Character.toUpperCase(c);
                    }else {
                        //word += Character.toLowerCase(c);
                        word[k] = Character.toLowerCase(c);
                    }
                        
                    j++;
                }else {  //not letter
                    //word += c;
                    word[k] = c;
                }
            }
            res.add(new String(word));
            
        }
        return res;
        
    }
}

