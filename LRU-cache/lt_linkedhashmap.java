/*lt java, directly uses Java LinkedHashMap, which is dedicated to LRU cache
runtime 64ms, faster than 100%

Java LinkedHashMap extends HashMap and maintains a linked list of the entries in the map, in the order in which they were inserted. This allows insertion-order iteration over the map. That is, when iterating a LinkedHashMap, the elements will be returned in the order in which they were inserted.

You can also create a LinkedHashMap that returns its elements in the order in which they were last accessed.

you might want to read LinkedHashMap.java for deeper 
*/
class LRUCache extends LinkedHashMap<Integer, Integer>{
    private int capacity;
    
    public LRUCache(int capacity) {
        //capacity, fill ratio, order: 
        //If Order is true, then access order is used. If Order is false, then insertion order is used.
        super(capacity, 0.75F, true);
        this.capacity = capacity;
    }

    public int get(int key) {
        return super.getOrDefault(key, -1);
    }

    public void put(int key, int value) {
        super.put(key, value);
    }

    @Override
    //Returns true if this map should remove its eldest entry.
    //controls how eldestEntry is removed
    protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
        return size() > capacity; 
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

