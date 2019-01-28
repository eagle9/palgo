/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface Master {
 *     public int guess(String word) {}
 * }
 */
// //code from leetcode/article
//runtime 2ms, faster than 96%
//not yet understand
class Solution {
   
    public void findSecretWord(String[] wordlist, Master master) {
        for (int i = 0, x = 0; i < 10 && x < 6; ++i) {
            String guess = wordlist[new Random().nextInt(wordlist.length)];
            x = master.guess(guess);
            List<String> wordlist2 = new ArrayList<>();
            for (String w : wordlist)
                if (match(guess, w) == x)
                    wordlist2.add(w);
            wordlist = wordlist2.toArray(new String[wordlist2.size()]);
        }
    }
    private int match(String a, String b) {
        int ans = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) == b.charAt(i)) ans++;
        }
        return ans;
    }
}

