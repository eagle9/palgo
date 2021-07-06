//lt idea similiar to shaun own
class Solution {
    private int[] orderMap = new int[26];
    public boolean isAlienSorted(String[] words, String order) {
        //order of each char
        
        for (int i = 0; i < order.length(); i++){
            orderMap[order.charAt(i) - 'a'] = i;
        }

        for (int i = 0; i < words.length - 1; i++) {
            if (compare(words[i], words[i+1]) > 0) return false;
        }

        return true;
    }
    private int compare(String word1, String word2) {
        //word[i] <= word[i+1] 
        if (word1.equals(word2)) return 0;
        for (int j = 0; j < word1.length(); j++) {
                // If we do not find a mismatch letter between words[i] and words[i + 1],
                // we need to examine the case when words are like ("apple", "app").
                if (j >= word2.length()) return 1;

                //char at j == continue
                if (word1.charAt(j) != word2.charAt(j)) {
                    int a = word1.charAt(j) - 'a';
                    int b = word2.charAt(j) - 'a';
                    if (orderMap[a] > orderMap[b]) return 1;
                    else return -1;
                    //else <=, test next j
                    // if we find the first different letter and they are sorted,
                    // then there's no need to check remaining letters
                    //char at j <, decided for this word, break to next word
                }
        }
        
        //no char diff found and word1 is shorter, j < word2.length
        return -1;
    }
}
