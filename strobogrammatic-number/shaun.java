class Solution {
    public boolean isStrobogrammatic(String num) {
        Map<Character,Character> map = new HashMap<>();
        map.put('1','1');
        map.put('0','0'); //missed this one on first try
        map.put('6','9');
        map.put('8','8');
        map.put('9','6');
        char [] original = num.toCharArray();
        int n = original.length;
        char [] str = new char[n];
        for (int i = 0; i < n; i++){
            if (!map.containsKey(original[i])) return false;
            str[n-1-i] = map.get(original[i]);
        }
        
        //String strob = String.valueOf(str); //this is very slow on shaun's first try
        //return strob.equals(num);
        //just compare with char []
        for (int i = 0; i < n; i++)
            if (str[i] != original[i]) return false;
        return true;
    }
}
