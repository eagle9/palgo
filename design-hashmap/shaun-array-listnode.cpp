struct Node {
    int key, val;
    Node* next;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next= NULL;
    }
    Node() {}
};

//https://my.oschina.net/yysue/blog/1864017
//combine array and linked list
//runtime 61ms, faster than 98%, mem less than 88%
class MyHashMap {
private:
    vector<Node*> buckets; //(10000);
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        buckets = vector<Node*>(10000);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int i = idx(key); //key to bucket index
        
        //initialize array bucket index i with a listNode
        if (buckets[i] == NULL)
            buckets[i] = new Node(-1,-1);  //dummy node, bug: you can not ListNode(key,value)
        
        Node* prev = find(buckets[i], key);
        if (prev->next == NULL)
            prev->next = new Node(key, value);
        else prev->next->val = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int i = idx(key);
        if (buckets[i] == NULL)
            return -1;
        Node* prev = find(buckets[i], key);
        return prev->next == NULL ? -1 : prev->next->val;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int i = idx(key);
        if (buckets[i] == NULL) return;
        Node* prev = find(buckets[i], key);
        
        if (prev->next == NULL) return;
        //prev  prev->next prev->next->next
        // . |------------------>
        prev->next = prev->next->next;
    }
    
    //go through linklist bucket, find node.key == key
    //return prev, why it is for remove
    Node* find(Node* head, int key) {
        Node* node = head, *prev = NULL;
        while (node && node->key != key) {
            prev = node;
            node = node->next;
        }
        //node == null or node.key = key
        //node == null, reached the end of bucket
        //node.key == key, found key
        
        //why return prev? because it is for remove
        return prev;
    }
    int idx(int key) { 
        //return Integer.hashCode(key) % buckets.length;
        return key % buckets.size();
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

