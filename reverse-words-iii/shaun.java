//jz beats 96%
class Solution1 {
    public String reverseWords(String s) {
        
        if (s == null || s.length() == 0){
            return "";
        }
        
        String[] array = s.split(" ");    
        StringBuilder b = new StringBuilder();
        
        for (int i = 0; i < array.length; i++){
            if (!array[i].equals("")){
                if(b.length() > 0){
                    b.append(" ");
                }
                
                b.append(new StringBuilder(array[i]).reverse().toString());
            }
        }
        
        return b.toString();
        
        
    }
}
//shaun's own idea and code, beats 67%
class Solution {
    public String reverseWords(String s) {
        
        if (s == null || s.length() == 0){
            return "";
        }
        
        String[] array = s.split(" ");    
        StringBuilder b = new StringBuilder();
        
        for (int i = 0; i < array.length; i++){
            String word = array[i];
            String word1 = word;
            if (word.length() > 1) {
                //String word1 = new StringBuilder(word).reverse().toString();
                word1 = reverse(word);
            }
            
            if (i > 0) b.append(" ");
            b.append(word1);
            
            /*
            if (!array[i].equals("")){
                if(b.length() > 0){
                    b.append(" ");
                }
                
                b.append(new StringBuilder(array[i]).reverse().toString());
            }
            */
        }
        return b.toString();
    }
    
    private String reverse(String str) {
        char [] c = str.toCharArray();
        int left = 0, right = c.length-1;
        while (left < right) {
            char temp = c[left];
            c[left] = c[right];
            c[right] = temp;
            left++;
            right--;
        }
        return String.valueOf(c);
    }
    
}

