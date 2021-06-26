/*
lt idea with Doubly Linked List
why doubly linked list? 
remove a node in O(1), needs both its prev and next
add a node right after head in O(1), needs the head of the list
pop a node at tail, so we need the tail of list
actually doubly linked list is not hard to implement once you have the following 3 api: 
removeNode (remove an existing )
addNode( always right after the head)
popTail
moveToHead

Runtime: 211 ms, faster than 5.14% of Java online submissions for LRU Cache.

*/
public class LRUCache {

  class Pair {
    int key;
    int value;
    public Pair(int key, int value) {
        this.key = key;
        this.value = value;
    }
    
  }

  private Map<Integer, Pair> cache = new HashMap<>();
  private int size;
  private int capacity;
  private LinkedList<Pair> list;

  public LRUCache(int capacity) {
    this.size = 0;
    this.capacity = capacity;

    this.list = new LinkedList<>();
  }

  public int get(int key) {
    Pair pair = cache.get(key);
    if (pair == null) return -1;

    // move the accessed node to the head;
    //remove the pair, then addFirst/offerFirst
    list.remove(pair);
    list.addFirst(pair);

    return pair.value;
  }

  public void put(int key, int value) {
    Pair pair = cache.get(key);

    if(pair == null) {
        
      if(size == capacity) {
        // pop the tail
        Pair tail = list.pollLast();
        cache.remove(tail.key);
        --size;
      }
      Pair newPair = new Pair(key,value);
      
      cache.put(key, newPair);
      list.addFirst(newPair);

      ++size;

      
    } else { //key already in the cache
      // update the value.
      pair.value = value;
      list.remove(pair);
      list.addFirst(pair);
      
    }
  }
}

