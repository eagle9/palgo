package org.voyiger.algo;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

//https://medium.com/@amarteja/add-bold-tag-in-string-e5f31b573298
//https://www.youtube.com/watch?v=4JPKLcpggCE

public class AddBoldTag {
    public String addBoldTag(String s, String[] dict) {

        if (s.length() == 0 || dict.length == 0) {
            return s;
        }

        boolean[] boldTable = new boolean[s.length()];
        int end = 0;

        for(int i = 0; i < s.length(); i++) {
            //try all words in dict to see if any word can start at i and end at end
            //find the max end
            for(String word : dict) {
                int wordLength = word.length();

                if(i + wordLength <= s.length() && s.substring(i, i + wordLength).equals(word)) {
                    end = Math.max(end , i + wordLength);
                }
            }
            boldTable[i] = end > i;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if(!boldTable[i]) {
                sb.append(s.charAt(i));
                continue;
            }
            else {
                int j = i;
                while( j < s.length() && boldTable[j])
                {
                    j++;
                }
                sb.append("<b>").append(s.substring(i, j)).append("</b>");
                i = j - 1;
            }
        }
        return sb.toString();
    }

    @Test
    public void test() {
        /*
        Example 1:
        Input:
        s = "abcxyz123"
        dict = ["abc","123"]
        Output:
        "<b>abc</b>xyz<b>123</b>"
        Example 2:
        Input:
        s = "aaabbcc"
        dict = ["aaa","aab","bc"]
        Output:
        "<b>aaabbc</b>c"
         */
        String s = "abcxyz123";
        String [] dict = {"abc","123"};
        assertEquals(addBoldTag(s, dict), "<b>abc</b>xyz<b>123</b>");
        String s2 = "aaabbcc";
        String [] dict2 = {"aaa","aab","bc"};
        assertEquals(addBoldTag(s2, dict2), "<b>aaabbc</b>c");
    }
}

