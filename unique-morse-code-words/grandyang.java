class Solution {
    //grandyang idea, shaun java code, beats 30%
    public int uniqueMorseRepresentations(String[] words) {
        String [] morse= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        Set<String> set = new HashSet<>();
        for (int i = 0; i < words.length; i++) {
            char [] chars = words[i].toCharArray();
            String mstr = "";
            for (int j = 0; j < chars.length; j++){
                mstr += morse[chars[j] - 'a'];
            }
            set.add(mstr);
        }
        return set.size();
    }
}
/*
讨论：这道题其实没有充分发挥其潜力，摩斯码的场景很好，只是作为一道Easy题未免有些可惜了。一个比较显而易见的follow up就是，给我们一个摩斯码，问其有几种可能的单词组，比如给我们一个"--...-."，那么我们知道至少有两种zen和gin，可能还有更多，这样是不是就更加有趣了呢？
*/
