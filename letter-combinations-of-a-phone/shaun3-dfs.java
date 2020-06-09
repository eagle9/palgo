/*                    1.  2.   
String [] letters = {"abc", ....}

shaun own idea and brave code, cur res style dfs
Runtime: 1 ms, faster than 80.56% of Java online submissions for Letter Combinations of a Phone Number.
Memory Usage: 39.4 MB, less than 6.16% of Java online submissions for Letter Combinations of a Phone Number.
*/
class Solution {
    String [] letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if (digits.length() ==0) return res;
        StringBuilder cur = new StringBuilder();
        helper(digits, 0, cur, res);
        return res;
    }
    
    void helper(String digits, int index, StringBuilder cur, List<String> res) {
        if (index == digits.length()) {
            res.add(cur.toString());
            return;
        }
        int digit = digits.charAt(index) - '2';
        //for digit at index, try all of its letters
        for (char ch: letters[digit].toCharArray()) {
            cur.append(ch);
            helper(digits, index+1, cur, res);
            cur.deleteCharAt(cur.length()-1);
        }
    }
}
