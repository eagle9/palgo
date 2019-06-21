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
//shaun own idea and code, accepted after fixing typos
//runtime 36ms, faster than 100%, mem less than 5%
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        unordered_map<Node*, Node*> m;
        while (cur) {
            Node* cur2 = new Node();
            cur2->val = cur->val;
            m[cur] = cur2;
            cur = cur->next;
        }
        
        cur = head;
        while (cur) {
            Node* cur2 = m[cur];
            cur2->next = m[cur->next];
            cur2->random = m[cur->random];
            cur = cur->next;
        }
        return m[head];
    }
};
