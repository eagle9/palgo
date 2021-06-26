/* LeetCode: tktripathy */
//https://leetcode.com/problems/design-skiplist/discuss/401335/Solution-for-1206.-Design-Skiplist-explained-with-comments-...
//runtime 512ms, faster than 9%, mem less than 100%
class Skiplist {
private:
    struct sle { int val; sle *down, *next; };
    vector<sle *> head;
    int level = 0;
    
    /* Debugging - visualize how the skip list looks */
    void visual(void) {
        for (int i = level; i >= 0; i--) {
            sle *p = head[i];
            cout << "Level " << i << ":";
            while(p) { if (p->val >= 0) cout << p->val << " "; p = p->next; }
            cout << endl;
        }
    }

public:
    Skiplist() {
        return;
    }

    bool search(int target) {
        sle *p = head[level];   /* start from the highest level */
        while (p) {
            if (p->val == target) return 1; /* found */
            /* If the next node is higher than target, descend down the column to lower level */
            if (p->next == NULL || (p->next && p->next->val > target)) { p = p->down; continue; }
            p = p->next;
        }
        return 0;
    }
    
    void add(int num) {
        int l = 0 /* start at level 0 */, once = 0;     /* at least one loop is required */ 
        sle *ln = NULL;                                 /* last lower node */
        while (!once++ || (rand() % 2)) {               /* at least once OR as long as coin flip is 1 */
            sle *n = new sle; n->val = num, n->down = ln, n->next = NULL;   /* allocate a skip list entry node, 
                                                        /* with down pointing to node in this column at level below */
            
            /* First time init of skip list - add a sentinel node and the new node */
            if (head.size() == 0) {                     
                sle *sn/*sentinel node */ = new sle; sn->val = INT_MIN, sn->next = n, sn->down = NULL;
                head.push_back(sn); return; 
            }
            
            /* Insert node at level l */
            sle *p = head[l], *last = NULL;
            while (p) { if (p->val >= num) { last->next = n; n->next = p; break; } last = p; p = p->next; }
            if (!p) last->next = n;

            /* We need one more level - promote the sentinel node to new level */
            if (++l > level) {
                sle *sn/*sentinel node */ = new sle; sn->val = INT_MIN; sn->next = NULL; sn->down = head[level];
                head.push_back(sn); 
                level++;
            }
            
            /* Record node at this level to be used for down field of node at upper level */
            ln = n;
        }
    }
    
    bool erase(int num) {
        sle *p = head[level]; /* start at highest level */ bool del = 0;
        while (p) {
            /* If next node is end of list or is greater than num, descend down the column */
            if (p->next == NULL || p->next->val > num) { p = p->down; continue; }
            
            /* if found, delete it at this level and continue on to next lower level */
            if (p->next && p->next->val == num) {   
                p->next = p->next->next; 
                del = 1; 
                p = p->down; continue; 
            }
            p = p->next;
        }
        return del;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
