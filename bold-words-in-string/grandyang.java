//same idea as add bold tag
//runtime 42ms, faster than 30%
class Solution {
    public String boldWords(String[] words, String S) {
        StringBuilder res = new StringBuilder();
        int n = S.length();
        int end = 0; //what is end??  end index of match
        boolean [] bold = new boolean[n];
        //iterate the string chars from 0 to n-1
        for (int i = 0; i < n; i++) {
            //check if each word in dict match s.substring(i,i+len)
            for (String word: words) {
                int len = word.length();
                if (i + len <= n && S.substring(i,i+len).equals(word)) {
                    end = Math.max(end,i+len);
                    //bold[i] = true;
                }
            }
            bold[i] = end > i;
        }
        
        //go over the string s from 0 to n-1 to transform it
        for (int i = 0; i < n; i++) {
            if (!bold[i]){
                res.append(S.charAt(i));
                continue;
            }
            //substring(i,?) match a word in dict
            int j = i;
            while (j < n && bold[j]) j++; //merge consecutive matches
            //j-1 is the last match
            String sub = S.substring(i,j); //chars from i to j-1
            //add bold tag
            res.append("<b>" + sub + "</b>");
            i = j-1; //next i = j, which is not yet checked, this is key
        }
        return res.toString();
        
    }
}
