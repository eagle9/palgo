/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
gy reservoir sampling
runtime 40ms, faster than 61%, mem less than 100%
first k elements from infinite stream, save to result；
从第j（k + 1 <= j <=  inf），p = k/j to keep jth element，则从A中随机选择一个元素并用该元素j替换它；否则直接淘汰该元素；
重复步骤2直到结束，最后集合A中剩下的就是保证随机抽取的k个元素。

*/


//from leetcode discussion, 
//rand() return a random number from 0 to RAND_MAX which is usually INT_MAX
// defined in #include<bits/stdc++.h> 
// practical use is to find random k samples from inifite stream
//runtime 36ms, faster than 86%, mem less than 12%
class Solution {

public:
    Solution(ListNode * head) {
        this->head = head;
    }
    
    //reservior sampling with k
    int getRandom() {
        int k = 1;
        ListNode* node = head;
        int i = 0;
        vector<int> reservoir(k);
        int res = node->val;
        //put 0 to k-1 elements into the k-sized reservoir
        while (i < k && node != nullptr) {
            reservoir[i] = node->val;
            node = node->next;
            i++;
        }
        i++; // i == k  =>  i == k+1
        
        //till the end of list
        while (node) {
            //for probability k/i, take a random index 0 to k-1 to replace with node->val
            if (rand() % i < k) {
                reservoir[rand() %k]  = node->val;
            }
            //update i and node for the loop
            i++;
            node = node->next;
        }
        if (!reservoir.empty()) res = reservoir[0]; 
        return res;// or return reservoir when k > 1;
    }
private:
    ListNode* head;
};

class Solution0 {
public:
    Solution0(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int count = 1;
        ListNode* cur = head->next;
        int res = head->val;
        while (cur) {
            count++;
            
            if (rand() % count == 0)  res = cur->val; //replace 
            cur = cur->next;
        }
        return res;
        
    }
    
    /*
    int getRandom() {
        int res = head->val, count = 1;
        ListNode *cur = head->next;
        while (cur) {
            count++;
            int j = rand() % count;
            if (j == 0) res = cur->val;
            
            cur = cur->next;
        }
        return res;
    } */
private:
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
