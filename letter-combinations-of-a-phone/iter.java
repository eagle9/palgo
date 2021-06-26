//grandyang iteration idea, beats 42%
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if (digits.length() == 0) return res;
        
        String [] dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        //key point: add(""), otherwise for string s : res loop wont enter
        res.add("");
        for (int i = 0; i < digits.length(); ++i) {
            List<String> t = new ArrayList<>();
            String str = dict[digits.charAt(i) - '0'];
            for (String s : res) {
                for (int j = 0; j < str.length(); ++j) {
                    t.add(s + str.substring(j,j+1));
                }
            }
            res = t;
        }
        return res;
    }
}
