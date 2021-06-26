/*
shaun's first batch of tries
Time Limit Exceeded


*/
class Solution {
    public List<String> findStrobogrammatic(int n) {
        char [] list = {'1','0','6','8','9'};
        //stuck, how to 
        char [] ch = new char[n];
        List<String> res = new ArrayList<>();
        helper(list,n,0, new char [n], res);
        return res;
    }
    //
    private void helper(char [] list, int n, int cur, char [] str, List<String> res) {
        if (cur == n) {
            char [] temp = strobo(str);
            for (int i = 0; i < str.length; i++) {
                if (str[i] !=  temp[i]) return;
            }
            if (str[0] == '0' && str.length > 1) return;
            String str1 = String.valueOf(str);
            if (!set.contains(str1))
                res.add(str1);
            return;
            
        } 
        for (int i = 0; i < list.length; i++) {
            str[cur] = list[i];
            helper(list, n, cur+1, str, res);
        }
    }
    private Map<Character,Character> map = null;
    private Set<String> set = new HashSet<>();
    public Solution() {
        map = new HashMap<>();
        map.put('1','1');
        map.put('0','0'); //missed this one on first try
        map.put('6','9');
        map.put('8','8');
        map.put('9','6');
    }

    public char [] strobo(char [] original) {
        
        int n = original.length;
        char [] str = new char[n];
        for (int i = 0; i < n; i++){
            str[n-1-i] = map.get(original[i]);
        }
        
        return str;

    }
}
