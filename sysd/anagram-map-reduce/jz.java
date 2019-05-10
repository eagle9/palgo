/**
 * Definition of OutputCollector:
 * class OutputCollector<K, V> {
 *     public void collect(K key, V value);
 *         // Adds a key/value pair to the output buffer
 * }
 */
 
 //jz sysd, beats 87%, shaun read and understand
public class Anagram {

    public static class Map {
        //key not used, map each word to it sorted char word
        public void map(String key, String value, OutputCollector<String, String> output) {
            // Output the results into output buffer.
            // Ps. output.collect(String key, String value);
            StringTokenizer tokenizer = new StringTokenizer(value);
            while (tokenizer.hasMoreTokens()) {
                String word = tokenizer.nextToken();
                String original = word;
                char[] chars = original.toCharArray();
                Arrays.sort(chars);
                String sorted = new String(chars);
                output.collect(sorted, word);
            }
        }
    }

    public static class Reduce {
        //merge list
        public void reduce(String key, Iterator<String> values, OutputCollector<String, List<String>> output) {
            // Output the results into output buffer.
            // Ps. output.collect(String key, List<String> value);
            List<String> results = new ArrayList<String>();
            while (values.hasNext()) {
                results.add(values.next());
            }
            output.collect(key, results);
        }
    }
}
