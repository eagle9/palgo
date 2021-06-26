class Solution {
    //shaun's own idea and code, beats 99%, accepted 3rd try
    public String reverseOnlyLetters(String S) {
        char [] chars = S.toCharArray();
        int left = 0, right = chars.length - 1;
        
        while (left < right) {
            //initialy if isLetter left++, does not work
            //keep going when left is in bound
            while (!Character.isLetter(chars[left]) && left < chars.length-1) left++;
            while (!Character.isLetter(chars[right]) && right > 1) right--;
            if (left < right) {
                char temp = chars[left];
                chars[left] = chars[right];
                chars[right] = temp;
                //dont' forget the following two operations
                left++;
                right--;
            }
            
        }
        return String.valueOf(chars);
    }
}
