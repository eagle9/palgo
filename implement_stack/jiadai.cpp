//Your submission beats 38.00% Submissions!
class Stack {
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    void push(int x) {
        // write your code here
        Node* node = new Node(x);
        node->next = head;
        head = node;
    }

    /* * @return: nothing */
    void pop() {
        Node* node = head;
        head = head->next;
        delete(node);
    }

    /* * @return: An integer */
    int top() {
        return head->val;
    }

    /* * @return: True if the stack is empty */
    bool isEmpty() {
        return head == nullptr;
    }
    
private:
    struct Node {
        int val;
        Node *next;
        Node(int v): val(v), next(nullptr) {}
    };
    Node *head = nullptr;
};
