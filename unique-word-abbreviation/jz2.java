//jz idea2, beats 1%, too slow
/*
重要的是理解题意：

当 word -> abbreviation 在字典的所有abbreviation中不存在时， return true
当 word 在字典中存在时, 如果没有其他字典中的词有相同的abbreviation, return true
*/
public class ValidWordAbbr {
    Map<String, Set<String>> map = new HashMap<>();
    Set<String> set = new HashSet<>();
    /*
    * @param dictionary: a list of words
    */public ValidWordAbbr(String[] dictionary) {
        // do intialization if necessary
        for (String s : dictionary) {
            if (s.length() <= 2) {
                continue;
            }
            
            String abbr = getAbbr(s);
            
            if (map.containsKey(abbr)) {
                map.get(abbr).add(s);
            } else {
                Set<String> set = new HashSet<>();
                set.add(s);
                map.put(abbr, set);
            }
            
            set.add(s);
        }
    }

    /*
     * @param word: a string
     * @return: true if its abbreviation is unique or false
     */
    public boolean isUnique(String word) {
        // write your code here
        if (set.contains(word)) {
            return map.get(getAbbr(word)).size() == 1;
        }
        return !map.containsKey(getAbbr(word));
    }
    
    private String getAbbr(String s) {
        if (s.length() <= 2) {
            return s;
        }
        
        s = s.substring(0, 1) + (s.length() - 2) + s.substring(s.length() - 1, s.length());
        System.out.println(s);
        return s;
    }
}
