class Solution {
    public String crackSafe(int n, int k) {
        char [] c = new char[n];
        for (int i = 0; i < n; i++)  c[i] = '0';
        String pass =  String.valueOf(c);
        String res = pass;
        Set<String> visited = new HashSet<>();
        visited.add(pass);
        //how many passwords?   k^n
        int P = (int)Math.pow(k,n);
        for (int i = 0; i < P;i++) {
            int len = res.length();
            String suffix = res.substring(len-n+1,len);
            //add 1 digit
            String newPass = null;
            //for (int j = 0; j <= k-1; j++) { //loop from 0 won't work, why?
            for (int j = k-1; j >=0; j--) {
                String str = String.valueOf(j);
                newPass = suffix + str;
                if (!visited.contains(newPass)) {
                    res += str;
                    visited.add(newPass);
                    break;
                }
            }
            //assume that newPass will already be updated with not null value
            
        }
        return res;
        
    }
}
