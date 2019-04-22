/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
/*第一遍扫的时候巧妙运用next指针， 开始数组是1->2->3->4  。 然后扫描过程中 先建立copy节点 1->1`->2->2`->3->3`->4->4`, 然后第二遍copy的时候去建立边的copy， 拆分节点, 一边扫描一边拆成两个链表，这里用到两个dummy node。第一个链表变回  1->2->3 , 然后第二变成 1`->2`->3`  */
//jz No HashMap version, shaun read and understand
//jz no hashmap idea, use next pointer to save the mapping
//shaun translates to cpp
//runtime 36ms, faster than 100%, mem less than 5%
class Solution {
private:
    void copyNext(Node* head) {
        while (head) {
            Node* newNode = new Node(head->val);
            newNode->random = head->random;
            newNode->next = head->next;
            head->next = newNode;
            head = head->next->next;
        }
    }

    void copyRandom(Node* head) {
        while (head) {
            if (head->next->random) {
                head->next->random = head->random->next;
            }
            head = head->next->next;
        }
    }

    Node* splitList(Node* head) {
        Node* newHead = head->next;
        while (head) {
            Node* temp = head->next;
            head->next = temp->next;
            head = head->next;
            if (temp->next) {
                temp->next = temp->next->next;
            }
        }
        return newHead;
    }

public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        copyNext(head);
        copyRandom(head);
        return splitList(head);
    }
};
