/*

//shaun came up very close to grandyang idea, puzzled when asked to do inplace change.
//key insight is that when you move i from 0 to len-1, changeIndex will lag i, so there is no interferences
// a loop for i to go from 0 to len-1, another loop and pointer to go through all repeating chars, then update with changeIndex/storeIndex
//runtime 8ms, faster than 88%, mem less than 99%

shaun may 17, quick and clear to the cutting idea: 2p with 1p as storeIndex
Runtime: 1 ms, faster than 93.45% of Java online submissions for String Compression.
Memory Usage: 39.3 MB, less than 6.82% of Java online submissions for String Compression.
*/
class Solution {
    public int compress(char[] chars) {
        int n = chars.length, changeIndex = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && chars[j] == chars[i]) ++j;
            //out of while loop, now i to j-1 all same char
            //len = j-1 -i + 1 = j - i
            chars[changeIndex++] = chars[i];
            if (j - i > 1) {
                for (char c : String.valueOf(j - i).toCharArray()) {
                    chars[changeIndex++] = c;
                }
            }
            i = j;
        }
        return changeIndex;
    }
};



