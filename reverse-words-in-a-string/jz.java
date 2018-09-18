//jz, beats 32%
public class Solution {
    /*
     * @param s: A string
     * @return: A string
     */
    public String reverseWords(String s) {
        // write your code here
        if(s.length() == 0 || s == null){
            return " ";
        }
        String[] array = s.split(" ");
        StringBuilder sb = new StringBuilder();
        
        for(int i = array.length - 1; i >= 0; i--){
            if(!array[i].equals("")) { //is a word
                if (sb.length() > 0) { // if sb already has word, add " "
                    sb.append(" ");
                }
                
                sb.append(array[i]);
            }
        }
        return sb.toString();
    }
}
