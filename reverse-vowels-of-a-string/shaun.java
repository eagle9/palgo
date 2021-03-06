//jz idea same as grandyang, beats 100%
public class Solution {
    /**
     * @param s: a string
     * @return: reverse only the vowels of a string
     */
    public String reverseVowels(String s) {
        // write your code here
        //right = s.length  IndexOutOfBoundsException
        int left =0, right = s.length()-1;
        char [] chars = s.toCharArray();
        while (left < right) {
            if (isVowel(chars[left]) && isVowel(chars[right])) {
                char temp = chars[left];
                chars[left] = chars[right];
                chars[right] = temp;
                left++;
                right--;
            }else {
                if (!isVowel(chars[left])) { //left not vowel
                    left++;
                }
                if (!isVowel(chars[right])) { //right not vowel
                    right--;
                }
            }
        }
        //left == right
        return String.valueOf(chars);
    }
    //simple code but slower, down from 100% to 84%
    private boolean isVowel(char c) {
        return "aeiouAEIOU".indexOf(c) >=0;
    }
    private boolean isVowel222(char c) {
        if (c == 'a' || c =='e' || c == 'i' || c == 'o' || c == 'u'||
            c == 'A' || c =='E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
            }
        else
            return false;
    }
}
