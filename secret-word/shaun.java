//shaun's own code, wrong answer so far
/*
does not pass
"aaaasds"
"gkg"


*/

public class Solution {
    /**
     * @param s: the long string
     * @param word: the secrect word
     * @return: whether a substring exists in the string can be transformed by the above encoding rule
     */
    public String getAns(String s, String word) {
        // Write a code here
        //same number of unique chars
        //index ---> char
        HashMap<Character,String> map1 = getMap(s);
        HashMap<Character,String> map2 = getMap(word);
        Set set1 = map1.keySet();
        Set set2 = map2.keySet();
        if (set1.size() < set2.size())
            return "no";
        
        Set<String> values1 = new HashSet<>();
        values1.addAll(map1.values());
        Set<String> values2 = new HashSet<>();
        values2.addAll(map2.values());
        
        for (String v2: values2) {
            if  (!values1.contains(v2))
                return "no";
        }
        return "yes";
        
    }
    
    private HashMap<Character, String> getMap(String s) {
        char [] source = s.toCharArray();
        //map store char --- > index list
        HashMap<Character, String> map = new HashMap<>();
        for (int i = 0; i < source.length; i++) {
            char c = source[i];
            if (!map.containsKey(c)) {
                map.put(c, String.valueOf(i));
            }else {
                String val = map.get(c);
                map.put(c, val + String.valueOf(i));
            }
        }
        return map;
    }
}
