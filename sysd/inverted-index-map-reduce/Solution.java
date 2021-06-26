//shaun, jz idea and code, beats 37.80%
/*
class OutputCollector<K, V> {
     public void collect(K key, V value);
         // Adds a key/value pair to the output buffer
}
 //Definition of Document:
class Document {
      public int id;
      public String content;
}
*/
public class InvertedIndex {
    
    public static class Map {
        //key -- not used, value/doc
        public void map(String key, Document doc,
                        OutputCollector<String, Integer> output) {
            // Output the results into output buffer.
            // Ps. output.collect(String key, int value);  word to its document id
            int id = doc.id;
            StringTokenizer tokenizer = new StringTokenizer(doc.content);
            while (tokenizer.hasMoreTokens()) {
                String word = tokenizer.nextToken();
                output.collect(word, id);
            }
            
        }
    }

    public static class Reduce {
        //input key(word), Iterator<Integer> values( doc ids that word occurred)
        //output -- words to bigger list of doc ids
        public void reduce(String key, Iterator<Integer> values,
                           OutputCollector<String, List<Integer>> output) {
            // Write your code here
            // Output the results into output buffer.
            // Ps. output.collect(String key, List<Integer> value);
            List<Integer> results = new ArrayList<Integer>();
            int previous = -1;
            while (values.hasNext()) {
                int now = values.next();
                if(previous != now) {
                    results.add(now);
                }
                previous = now;
            }
            output.collect(key, results);
        }
    }
}

