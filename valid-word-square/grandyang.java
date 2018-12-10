public class Solution {
    /**
     * @param words: a list of string
     * @return: a boolean
     */
     //grandyang fishercode idea, beats 54%
    public boolean validWordSquare(String[] words) {
        int ROWS = words.length;
        for (int i = 0; i < ROWS; i++) {
            String word = words[i];
            int COLS = word.length();
            for (int j = 0; j < COLS; j++) {
                if (j >= ROWS) {
                    return false;
                }
                if (i >= words[j].length()) {
                    return false;
                }
                if (word.charAt(j) != words[j].charAt(i)) {
                    return false;
                }
            }
        }
        //passed all tests
        return true;
    }
}
