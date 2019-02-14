//shaun own first try, array index out of bound, then wrong answer
class Solution0 {
   public boolean validWordAbbreviation(String word, String abbr) {
        char [] a = abbr.toCharArray();
        char [] w = word.toCharArray();
        int j = 0, i = 0;
        for (; i < a.length && j < w.length;i++,j++){

            int number = 0;
            while (i < a.length && a[i] >= '0' && a[i] <= '9') {
                //if (number == 0 && a[i] == '0') return false;
                number = 10 * number + (a[i++] - '0');

            }
            //now a[i] is letter
            j += number;
            //w[j]
            if (j >= w.length) return false;
            if (i < a.length && a[i] != w[j]) return false;
        }
        return true;
    }
}
/*
Runtime: 9 ms, faster than 91.51% of Java online submissions for Valid Word Abbreviation.
Memory Usage: 38 MB, less than 0.78% of Java online submissions for Valid Word Abbreviation.
grandyang two pointer
*/
class Solution {
    public boolean validWordAbbreviation(String word, String abbr) {
        char [] a = abbr.toCharArray();
        char [] w = word.toCharArray();
        int j = 0, i = 0;
        for (; i < a.length && j < w.length;){
            if (a[i] >= '0' && a[i] <= '9') {
                if (a[i] == '0') return false;
                int number = 0;
                //put i < a.length at first !!!!
                while (i < a.length && a[i] >= '0' && a[i] <= '9' ) {
                    //if (number == 0 && a[i] == '0') return false;
                    number = 10 * number + (a[i++] - '0');

                }
                j += number;
                
            }
            else {
                if (a[i++] != w[j++]) return false;
            }
            
        }
        return i == a.length && j == w.length;
    }
}
/*
Runtime: 10 ms, faster than 54% of Java online submissions for Valid Word Abbreviation.
Memory Usage: 38.1 MB, less than 0.78% of Java online submissions for Valid Word Abbreviation.

*/
public class Solution2 {
    public boolean validWordAbbreviation(String word, String abbr) {
        int i = 0, j = 0;
        char [] w = word.toCharArray();
        char [] a = abbr.toCharArray();
        while (i < w.length && j < a.length) {
            if (w[i] == a[j]) {
                i++;
                j++;
            } else if (a[j] > '0' && a[j] <= '9') {     //notice that 0 cannot be included
                int start = j;
                while (j < a.length && Character.isDigit(a[j])) {
                    j++;
                }
                i += Integer.valueOf(abbr.substring(start, j));
            } else {
                return false;
            }
        }
        return (i == w.length && j == a.length);
    }
}
