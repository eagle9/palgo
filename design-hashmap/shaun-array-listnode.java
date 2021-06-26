//https://my.oschina.net/yysue/blog/1864017
//combine array and linked list
//runtime 61ms, faster than 98%, mem less than 88%
class MyHashMap {
    final ListNode[] buckets = new ListNode[10000];

    public void put(int key, int value) {
        int i = idx(key); //key to bucket index
        
        //initialize array bucket index i with a listNode
        if (buckets[i] == null)
            buckets[i] = new ListNode(-1,-1);  //dummy node, bug: you can not ListNode(key,value)
        
        ListNode prev = find(buckets[i], key);
        if (prev.next == null)
            prev.next = new ListNode(key, value);
        else prev.next.val = value;
       
    }

    public int get(int key) {
        int i = idx(key);
        if (buckets[i] == null)
            return -1;
        ListNode prev = find(buckets[i], key);
        return prev.next == null ? -1 : prev.next.val;
        
    }

    public void remove(int key) {
        int i = idx(key);
        if (buckets[i] == null) return;
        ListNode prev = find(buckets[i], key);
        
        if (prev.next == null) return;
        prev.next = prev.next.next;
        
    }

    int idx(int key) { 
        //return Integer.hashCode(key) % buckets.length;
        return key % buckets.length;
    }
    
    //go through linklist bucket, find node.key == key
    //return prev, why it is for remove
    ListNode find(ListNode head, int key) {
        ListNode node = head, prev = null;
        while (node != null && node.key != key) {
            prev = node;
            node = node.next;
        }
        //node == null or node.key = key
        //node == null, reached the end of bucket
        //node.key == key, found key
        
        //why return prev? because it is for remove
        return prev;
        
    }
}

class ListNode {
    int key, val;
    ListNode next;

    ListNode(int key, int val) {
        this.key = key;
        this.val = val;
        //this.next= null;
    }
}
