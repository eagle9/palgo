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

runtime 56ms, faster than 91.73%, mem less than 65%

*/
public class LRUCache {

  class DLinkedNode {
    int key;
    int value;
    DLinkedNode prev;
    DLinkedNode next;
  }

    //add the new node right after head
    //head    node   b(head.next)
  private void addNode(DLinkedNode node) {
    DLinkedNode b = head.next;
    
    node.prev = head;
    node.next = b;
    //head.next.prev = node;
    head.next = node;
    b.prev = node;
  }

    //prev   node   next
    //remove an existing node from linked list
  private void removeNode(DLinkedNode node){
    DLinkedNode prev = node.prev;
    DLinkedNode next = node.next;

    prev.next = next;
    next.prev = prev;
  }

    //move a node in between to the head
  private void moveToHead(DLinkedNode node){
    removeNode(node);
    addNode(node);
  }

    //pop the current tail
  private DLinkedNode popTail() {
    DLinkedNode res = tail.prev;
    removeNode(res);
    return res;
  }

  private Map<Integer, DLinkedNode> cache = new HashMap<>();
  private int size;
  private int capacity;
  private DLinkedNode head, tail;

  public LRUCache(int capacity) {
    this.size = 0;
    this.capacity = capacity;

    head = new DLinkedNode();
    // head.prev = null;

    tail = new DLinkedNode();
    // tail.next = null;

    head.next = tail;
    tail.prev = head;
  }

  public int get(int key) {
    DLinkedNode node = cache.get(key);
    if (node == null) return -1;

    // move the accessed node to the head;
    moveToHead(node);

    return node.value;
  }

  public void put(int key, int value) {
    DLinkedNode node = cache.get(key);

    if(node == null) {
      DLinkedNode newNode = new DLinkedNode();
      newNode.key = key;
      newNode.value = value;

      cache.put(key, newNode);
      addNode(newNode);

      ++size;

      if(size > capacity) {
        // pop the tail
        DLinkedNode tail = popTail();
        cache.remove(tail.key);
        --size;
      }
    } else { //key already in the cache
      // update the value.
      node.value = value;
      moveToHead(node);
    }
  }
}
