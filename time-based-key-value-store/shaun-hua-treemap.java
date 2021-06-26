/*

Runtime: 140 ms, faster than 51.19% of Java online submissions for Time Based Key-Value Store.
Memory Usage: 115 MB, less than 100.00% of Java online submissions for Time Based Key-Value Store.

*/
class TimeMap {

    /** Initialize your data structure here. */
    public TimeMap() {
        m_ = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        TreeMap<Integer,String> values = m_.getOrDefault(key,new TreeMap<>());
        values.put(timestamp,value);
        if (!m_.containsKey(key))
            m_.put(key, values);
       
    }
    
    public String get(String key, int timestamp) {
        TreeMap<Integer,String> values = m_.get(key);
        if (values == null) return "";
        //find a key in many keys <= given timestamp (floor, but max out)
        //   the key should be max
        Integer k = values.floorKey(timestamp); // max key <= timestamp
        if (k == null) return "";
        return values.get(k);
    }
    private Map<String,TreeMap<Integer,String>> m_;
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */


