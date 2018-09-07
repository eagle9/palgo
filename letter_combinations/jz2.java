//Your submission beats 87.80% Submissions!

public class Solution {
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    public List<String> letterCombinations(String digits) {
        // write your code here
        List<String> res = new ArrayList<>();
        if (digits.length() == 0) {
            return res;
        }
        res.add("");
        Map<Character, char[]> map = new HashMap<>();
        map.put('2', new char[]{'a', 'b', 'c'});
        map.put('3', new char[]{'d', 'e', 'f'});
        map.put('4', new char[]{'g', 'h', 'i'});
        map.put('5', new char[]{'j', 'k', 'l'});
        map.put('6', new char[]{'m', 'n', 'o'});
        map.put('7', new char[]{'p', 'q', 'r', 's'});
        map.put('8', new char[]{'t', 'u', 'v'});
        map.put('9', new char[]{'w', 'x', 'y', 'z'});
        for (char c:digits.toCharArray()) {
            List<String> tmp = new ArrayList<>();
            for (String str:(ArrayList<String>)res) {
                for (char mappingChar:map.get(c)) {
                    tmp.add(str + mappingChar);
                }
            }
            res = new ArrayList(tmp);
        }
        return res;
    }
}
