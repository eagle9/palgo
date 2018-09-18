//jz, linhuchong, 3 steps, Your submission beats 98.01% Submissions!
public class Solution {
    /**
     * @param str: a string
     * @return: return a string
     */
    public char[] reverseWords(char[] str) {
        if(str == null || str.length == 0){
            return str;
        }
        
        //reverse entire array
        reverse(str, 0, str.length - 1);
        
        
        int index = 0; //index for word start
        //revere each word
        for(int i = 0; i < str.length; i++){
            if(str[i] == ' '){
                reverse(str, index, i - 1);
                index = i + 1; // i-1 space i+1
            }
        }
        
        //reverse last word, each word ends with space or end_of_string
        reverse(str, index, str.length - 1);
        
        return str;
    }
    
    private void reverse(char[] str, int start, int end){
        while(start < end){ //shaun modified start <= end, = is not needed
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
    }
}
