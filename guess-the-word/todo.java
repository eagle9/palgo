/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface Master {
 *     public int guess(String word) {}
 * }
 */
class Solution {
    public void findSecretWord(String[] wordArray, Master master) {
        
        List<String> wordlist = new ArrayList<>();
        for (String word: wordArray) {
            wordlist.add(word);
        }
        Random random = new Random();
        String target = wordArray[random.nextInt(Integer.MAX_VALUE) % wordArray.length];
        int count = 10;
        while(count--> 0 ){
            int matches = master.guess(target);
            
            shrinkWordList(wordlist, target, matches);
            
            target = wordlist.get( random.nextInt(Integer.MAX_VALUE) % wordlist.size());
        }
        String [] res = new String[wordlist.size()];
        for (int i = 0; i < res.length; i++) {
            res[i] = wordlist.get(i);
        }
        wordArray = res;
    }
    
    int match(String a, String b) {
        int ans = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) == b.charAt(i)) ans++;
        }
        return ans;
    }
    void shrinkWordList(List<String> wordList, String guessWord, int matches) {
        List<String> tmp = new ArrayList<>();
        for (String word: wordList) {
            int m = match(word, guessWord);
            if (m == matches) tmp.add(word);
        }
        wordList = tmp;
    }
}


