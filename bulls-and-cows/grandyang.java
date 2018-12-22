public class Solution {
    public class S1 {
        //grandyang idea 1, shaun java code, beats 74%
        public String getHint(String secret, String guess) {
            int [] m = new int[256];
            int bulls = 0, cows = 0;
            for (int i = 0; i < secret.length(); ++i) {
                if (secret.charAt(i) == guess.charAt(i)) ++bulls;
                else ++m[secret.charAt(i)];
            }
            for (int i = 0; i < secret.length(); ++i) {
                //guess position not right, but guessed number is in, by def, it is cow
                if (secret.charAt(i) != guess.charAt(i) && m[guess.charAt(i)] > 0) {
                    ++cows;
                    --m[guess.charAt(i)];
                }
            }
            return String.valueOf(bulls) + "A" + String.valueOf(cows) + "B";
        }
    }
    
    //grandyang idea2, one loop, but much harder to come up with. i would stick with idea1
    //beats 
    public String getHint(String secret, String guess) {
        int [] m = new int[256];
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.length(); ++i) {
            char a = secret.charAt(i);
            char b = guess.charAt(i);
            if (a == b) ++bulls;
            else {
                //a is in guess word
                if (m[a] < 0) {
                    ++cows;
                }
                //record a into m
                m[a]++;
                /*above equivalent to 
                if (m[a]++ < 0)  ++cows;
                
                */
                
                //guess b is in secret word
                if (m[b] > 0) {
                    ++cows;
                    
                }
                m[b]--;
            }
        }
        return String.valueOf(bulls) + "A" + String.valueOf(cows) + "B";
    }
     
};
