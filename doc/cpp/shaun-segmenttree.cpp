//shaun own try to code segment tree and do its application 
//first sub wrong answer
//accepted fixing 1 bug checking hua's pseudo code
//runtime 32ms, faster than 97%, mem less than 7%
//307 range sum query mutable
class SegmentTreeNode {
public:
    SegmentTreeNode(int start, int end) {
        this->start = start; 
        this->end = end;
        this->left = NULL; 
        this->right = NULL;
    }
//private:
    int start, end, sum;
    SegmentTreeNode * left, *right;
    
};

class NumArray {
public:
    NumArray(vector<int>& nums) {
        root = build(nums, 0, nums.size()-1);
    }
    
    void update(int i, int val) {
        update(root, i, val);
    }
    void update(SegmentTreeNode* node, int i, int val) {
        if (i == node->start && i == node->end) {
            node->sum = val;
            return;
        }
        int mid = node->start + (node->end - node->start)/2;
        if (i <= mid) update(node->left, i, val);
        else update(node->right, i, val);
        //start != end, still need to update its sum!!!! hua mentioned this, i learned lesson though bug fixing
        node->sum = node->left->sum + node->right->sum; //bug --- missing this first try
    }
    int sumRange(int i, int j) {
        return queryRange(root,i,j);
    }
    int queryRange(SegmentTreeNode* node, int i, int j) {
        if (i > j) return 0;
        if (i == node->start && j == node->end) return node->sum;
        int mid = node->start + (node->end - node->start)/2;
        //i j<= mid
        if (j <= mid) return queryRange(node->left, i,j);
        //   mid < i j
        if (mid < i)  return queryRange(node->right, i, j);
        //    i mid j
        return queryRange(node->left, i, mid) + queryRange(node->right, mid+1,j);
    }
private:
    SegmentTreeNode * root;
    SegmentTreeNode* build(vector<int>& nums, int i, int j) {
        
        if (i > j) return NULL;
        SegmentTreeNode* node = new SegmentTreeNode(i,j);
        
        if (i == j){
            node->sum = nums[i];
            return node;
        }
        
        int mid = i + (j-i)/2;
        SegmentTreeNode* nodeLeft = build(nums, i, mid);
        SegmentTreeNode* nodeRight = build(nums, mid+1, j);
        node->left = nodeLeft;
        node->right = nodeRight;
        node->sum = nodeLeft->sum + nodeRight->sum;
        return node;
    }

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
