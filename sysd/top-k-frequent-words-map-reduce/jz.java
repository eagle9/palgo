/**
 * Definition of OutputCollector:
 * class OutputCollector<K, V> {
 *     public void collect(K key, V value);
 *         // Adds a key/value pair to the output buffer
 * }
 * Definition of Document:
 * class Document {
 *     public int id;
 *     public String content;
 * }
 */
 
//jz beats 92.20%, shaun red and understand
//top k, natural to use priorityQueue. minHeap or maxHeap?
//get familiar with mapper and reducer api 
class Pair {
    String key; //store word
    int value; //store word count
    
    Pair(String key, int value) {
        this.key = key;
        this.value = value;
    }
}

public class TopKFrequentWords {
    //define both Map and Reduce class
    //Mapper input key value, output collector
    //Reducer input key, Iterator<Value>, output collector
    public static class Map {
        public void map(String _, Document value,
                        OutputCollector<String, Integer> output) {
            // Write your code here
            // Output the results into output buffer.
            // Ps. output.collect(String key, int value);
            int id = value.id;
            String content = value.content;
            String[] words = content.split(" ");
            for (String word : words)
                if (word.length() > 0) {
                    output.collect(word, 1);
                }
        }
    }

    public static class Reduce {
        private PriorityQueue<Pair> Q = null;
        private int k;

        private Comparator<Pair> pairComparator = new Comparator<Pair>() {
            public int compare(Pair left, Pair right) {
                if (left.value != right.value) {
                    return left.value - right.value;
                }
                return right.key.compareTo(left.key);
            }
        };

        public void setup(int k) {
            // initialize your data structure here
            this.k = k;
            Q = new PriorityQueue<Pair>(k, pairComparator);
        }   

        public void reduce(String key, Iterator<Integer> values) {
            // Write your code here
            int sum = 0;
            while (values.hasNext()) {
                    sum += values.next();
            }

            Pair pair = new Pair(key, sum);
            if (Q.size() < k) {
                Q.add(pair);
            } else {
                Pair peak = Q.peek();
                //minHeap, min at the top, smaller removed, larger enter
                if (pairComparator.compare(pair, peak) > 0) {
                    Q.poll();
                    Q.add(pair);
                }
            }
        }

        public void cleanup(OutputCollector<String, Integer> output) {
            // Output the top k pairs <word, times> into output buffer.
            // Ps. output.collect(String key, Integer value);
            List<Pair> pairs = new ArrayList<Pair>();
            while (!Q.isEmpty()) {
                pairs.add(Q.poll());
            }

            // reverse result
            int n = pairs.size();
            for (int i = n - 1; i >= 0; --i) {
                Pair pair = pairs.get(i);
                output.collect(pair.key, pair.value);
            }
        }
    }
}

