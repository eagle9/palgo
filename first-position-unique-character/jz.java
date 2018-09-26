//jz beats 97.80%
public class Solution {
    /**
     * @param s a string
     * @return it's index
     */
    public int firstUniqChar(String s) {
        // Write your code here
        int[] alp = new int[256];
        char[] arr =s.toCharArray();

        for(char c : arr ){
            alp[c]++;
        }

        for(int i = 0; i < arr.length; i++){
            if (alp[arr[i]]==1) return i;
        }

        return -1;
    }
}
