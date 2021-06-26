/*


grandyang idea1, beats 34%
this idea is not easy to understand
*/
class Solution1 {
    public int wordsTyping(String[] sentence, int rows, int cols) {
        String all = "";
        for (String word : sentence) all += word + " ";
        int start = 0, len = all.length();
        for (int i = 0; i < rows; i++) {
            start += cols;
            if (all.charAt(start % len) == ' ') {
                ++start;
            } else {
                while (start > 0 && all.charAt((start - 1) % len) != ' ') {
                    --start;
                }
            }
        }
        return start / len;
    }
}
/*
grandyang idea2, beats 15%, easier to understand
this problem is not very typical. not a dp. 
统计加空格的句子总长度，然后遍历每一行，初始化colsRemaining为cols，然后还需要一个变量idx，来记录当前单词的位置，如果colsRemaining大于0，就进行while循环，如果当前单词的长度小于等于colsRemaining，说明可以放下该单词，那么就减去该单词的长度就是剩余的空间，然后如果此时colsRemaining仍然大于0，则减去空格的长度1，然后idx自增1，如果idx此时超过单词个数的范围了，说明一整句可以放下，那么就有可能出现宽度远大于句子长度的情况，所以我们加上之前放好的一句之外，还要加上colsRemaining/len的个数，然后colsRemaining%len是剩余的位置，此时idx重置为0


*/


class Solution {
    public int wordsTyping(String[] sentence, int rows, int cols) {
        String all = "";
        //even last word followed by a space??? yes. sentence + " " + sentence
        for (String word: sentence) all += (word + " ");
        int res = 0;
        int idx = 0; //word index in the sentence
        int n = sentence.length; //word count
        int len = all.length(); //sentence string length
        for (int i = 0; i < rows; i++) {
            int colsRemaining = cols;
            while (colsRemaining > 0) {
                //current row has enough space for current word at idx
                if (sentence[idx].length() <= colsRemaining) {
                    colsRemaining -= sentence[idx].length();
                    //a space follows the word just put
                    if (colsRemaining > 0) colsRemaining -= 1;
                    //all words are put
                    if (++idx >= n) {
                        res += 1 + colsRemaining/len; //quicker
                        colsRemaining %= len;
                        //res++;//with out colsRemaining %= len, accepted too, just much slower
                        idx = 0;
                    }
                }else {//not enough space at current row, go to next row
                    break;
                }
            }
        }
        return res;
    }
}

