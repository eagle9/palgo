//grandyang idea, key to use two reverse, kind of qiaomiao to think of that
//beats 29%
/*
由于之前那道题我们就是用in-place的方法做的，而这道题反而更简化了题目，因为不考虑首尾空格了和单词之间的多空格了，方法还是很简单，先把每个单词翻转一遍，再把整个字符串翻转一遍，或者也可以调换个顺序，先翻转整个字符串，再翻转每个单词
*/
class Solution {
    public void reverseWords(char[] str) {
        int begin = 0; 
        for (int i = 0; i <= str.length; i++) { //key point, i can be = length
            //if (str[i] == ' ' || i == str.length) {  //does not work, index outbound
            if (i == str.length || str[i] == ' ' ) { //end of word
                reverse(str, begin, i-1);
                begin = i+1; //update begin
            }
        }
        reverse(str, 0, str.length-1);
        
    }
    
    private void reverse(char [] c, int left, int right) {
        while (left < right) {
            char t = c[left];
            c[left]= c[right];
            c[right] = t;
            left++;
            right--;
        }
    }
}
