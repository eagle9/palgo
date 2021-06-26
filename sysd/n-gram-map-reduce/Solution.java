/**
 * Definition of OutputCollector:
 * class OutputCollector<K, V> {
 *     public void collect(K key, V value);
 *     // Adds a key/value pair to the output buffer
 * }
 */
//jz java, shaun read and understand
public class NGram {
	//any substr of len n to its count
	//similar to word count
    public static class Map {
        public void map(String _, int n, String str,
                        OutputCollector<String, Integer> output) {
            // Output the results into output buffer.
            // Ps. output.collect(String key, Integer value);
            for (int index = 0; index < str.length() - n + 1; ++index) {
                output.collect(str.substring(index, index + n), 1);
            }
        }
    }

    public static class Reduce {
        public void reduce(String key, Iterator<Integer> values,
                           OutputCollector<String, Integer> output) {
            // Output the results into output buffer.
            // Ps. output.collect(String key, int value);
            int sum = 0;
            while (values.hasNext()) {
            	sum += values.next();
            }
            output.collect(key, sum);
        }
    }
}
