//jz idea, the keypoint for this problem is to understand the problem correctly, what does it mean being unique!!!!
//beats 9%
public class ValidWordAbbr {
    Map<String, Integer> dict = new HashMap<>();
    Map<String, Integer> abbr = new HashMap<>();

    // @param dictionary a list of word
    public ValidWordAbbr(String[] dictionary) {
        // Write your code here
        for (String d : dictionary) {
            dict.put(d, dict.getOrDefault(d, 0) + 1);
            String a = getAbbr(d);
            abbr.put(a, abbr.getOrDefault(a, 0) + 1);
        }
    }
    /**
     * @param word a string
     * @return true if its abbreviation is unique or false
     */
    public boolean isUnique(String word) {
        // Write your code here
        String a = getAb(word);
        int count1 = dict.getOrDefault(word,0), count2 = abbr.getOrDefault(a,0);
        return count1 == count2;
        
        //using intValue requires not null
        //return dict.get(word).intValue() == abbr.get(a).intValue();
    }

    //good idea to come up with this function, since it will be used twice
    //getAb shaun's version
    String getAb(String word) {
        int n = word.length();
        if (n <= 2) return word;
        return word.substring(0,1) + String.valueOf(n-2) + word.substring(n-1,n);
    }
    
    String getAbbr(String str) {
        if (str.length() <= 2) {
            return str;
        }
        return "" + str.charAt(0) + (str.length() - 2) + str.charAt(str.length() - 1);
    }
}
