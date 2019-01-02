/*grandyang dfs, beats 81%
用递归Recursion来解，我们需要建立一个字典，用来保存每个数字所代表的字符串，然后我们还需要一个变量level，记录当前生成的字符串的字符个数，实现套路和上述那些题十分类似。在递归函数中我们首先判断level，如果跟digits中数字的个数相等了，我们将当前的组合加入结果res中，然后返回。否则我们通过digits中的数字到dict中取出字符串，然后遍历这个取出的字符串，将每个字符都加到当前的组合后面，并调用递归函数即可
*/
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if (digits.length() == 0) return res;
        //               0   1    2      3       4
        String [] dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helper(digits, dict, 0, "", res);
        return res;
    }
    
    //think of recursion tree, each level for a digit
    //      23
    //level 0:   a  b   c
    //level 1: def def  def
    
    private void helper(String digits, String [] dict, int level, String comb, List<String> res) {
        if (level == digits.length()) {
            res.add(comb);  //comb is value, not reference
            return;
        }
        //work on digit at the level, get corresponding letter string
        String str = dict[digits.charAt(level) - '0'];
        //try all possible letters
        for (int i = 0; i < str.length(); ++i) {
            helper(digits, dict, level + 1, comb + str.substring(i,i+1), res);
        }
    }
}
