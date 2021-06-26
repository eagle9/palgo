//grandyang v3, use deque, code very simple, beats 45%
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {}
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        return (index >= 0 && index < data.size()) ? data[index] : -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        data.push_front(val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        data.push_back(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > data.size()) return;
        data.insert(data.begin() + index, val);
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= data.size()) return;
        data.erase(data.begin() + index);
    }
    
private:
    deque<int> data;
};
