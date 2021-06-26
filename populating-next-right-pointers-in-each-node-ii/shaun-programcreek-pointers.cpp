/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
//https://www.programcreek.com/2014/06/leetcode-populating-next-right-pointers-in-each-node-ii-java/
/*programcreek two level (head and cur pointers)
                      (1)
                     / .  \
prevHead(prevCur)-> (2) ->  (3)
                   /    \      \
      head(cur)   (4)   (5)    (7)

*/
//runtime 400ms, faster than 76%, mem less than 99%
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;

        Node* prevHead = root;//previous level's head 
        Node* prevCur = nullptr;//previous level's pointer
        Node* head = nullptr;//currnet level's head 
        Node* cur = nullptr;//current level's pointer

        while(prevHead){
            prevCur = prevHead;

            while(prevCur){
                //left child is not null
                if(prevCur->left)    {
                    if(head == nullptr){
                        head = prevCur->left;
                        cur = prevCur->left;
                    }else{
                        cur->next = prevCur->left;
                        cur = cur->next;
                    }
                }

                //right child is not null
                if(prevCur->right){
                    if(head == nullptr){
                        head = prevCur->right;
                        cur = prevCur->right;
                    }else{
                        cur->next = prevCur->right;
                        cur = cur->next;
                    }
                }
                prevCur = prevCur->next;
            }

            //update last head
            prevHead = head;
            head = nullptr;
        }
        return root;
    }
};
