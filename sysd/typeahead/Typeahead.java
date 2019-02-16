import java.util.*;
public class Typeahead {
    // @param dict: A dictionary of words dict
    public Typeahead(Set<String> dict) {
        // do initialize if necessary
        for (String word : dict) {
            int n = word.length();
            for (int i = 0; i < n; ++i) { //start
                for (int j = i + 1; j <= n; ++j) { //end
                    String s = word.substring(i, j);
                    if (!words.containsKey(s)) {  
						List<String> list = new ArrayList<>();
						list.add(word);
                        words.put(s,list); //substring => word
                    }
					else {
						List<String> list = words.get(s);
						if (!list.get(list.size()-1).equals(word)) 
							list.add(word);

					}
                }
            }
        }
		System.out.println(words.size());
    }
    
    // @param str: a string
    // @return a set of words
    List<String> search(String str) {
        // Write your code here
        return words.get(str);
    }
    
    private Map<String, List<String>> words = new HashMap<>();

	public static void main(String [] args) {
		Set<String> set = new HashSet<>();
		String [] a = {"Jason Zhang", "James Yu", "Bob Zhang", "Larry Shi"};
		for (String word: a) 
			set.add(word);
		Typeahead t = new Typeahead(set);	
		for (String str: t.search("Zhang")) 
			System.out.println(str);
		for (String str: t.search("James")) 
			System.out.println(str);
		
	}
};
