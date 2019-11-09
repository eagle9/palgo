/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
      1
    2    3 
   4 5  6 7
pre: root left right
  grow left util left contains all numbers in left2
   try left size = 1 to 
   this way we can split left and right subtree
   how to make this split more efficient? 
   use set?  split takes O(n)
post: left2 right2 root

huahua idea
runtime 8ms, faster than 86%, mem less than 83%
pre[0] is root, pre[1] is the root of left subtree
pre: root left right

post: left right root
use pre[1] to split
*/


//shaun own try with hua's idea, but using index left to right inclusive
//runtime 8ms, faster than 86%, mem less than 33%
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        this->pre = pre;
        this->post = post;
        return helper(0, pre.size()-1, 0, post.size()-1);
    }
private:
    vector<int> pre;
    vector<int> post; 
    //pre: root left_sub_tree right_sub_tree
    //post: left_sub_tree[end is post_m]  right_sub_tree root
    //find left_sub_tree's root position in post 
    TreeNode* helper(int pre_l, int pre_r, int post_l, int post_r) {
        if (pre_l > pre_r) return NULL; //nullptr;
        TreeNode* root = new TreeNode(pre[pre_l]);  //pre_l 
        ++pre_l; // pre_l+1 is the root of left sub tree
        --post_r; //post: left_sub  right_sub  root
        if (pre_l > pre_r) return root;
      
        int post_m = post_l;
        for (; post_m <= post_r; ++post_m) {
            if (post[post_m] == pre[pre_l]) break;
        }
        
        int pre_m = pre_l + (post_m - post_l);
        root->left = helper(pre_l, pre_m, post_l, post_m);
        root->right = helper(pre_m+1, pre_r, post_m+1, post_r);
        return root;
    }
};


class Solution1 {
public:
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    return constructFromPrePost(cbegin(pre), cend(pre), cbegin(post), cend(post));
  }
private:
  typedef vector<int>::const_iterator VIT;
  TreeNode* constructFromPrePost(VIT pre_l, VIT pre_r, VIT post_l, VIT post_r) {
    if (pre_l == pre_r) return nullptr;
    TreeNode* root = new TreeNode(*pre_l);  //pre_l 
    ++pre_l; // pre_l+1 is the root of left sub tree
    --post_r;
    if (pre_l == pre_r) return root;
      
    //pre: root left_sub_tree right_sub_tree
    //post: left_sub_tree[end is post_m]  right_sub_tree root
    //find left_sub_tree's root position in post 
    VIT post_m = next(find(post_l, post_r, *pre_l));
    VIT pre_m = pre_l + (post_m - post_l);
    root->left = constructFromPrePost(pre_l, pre_m, post_l, post_m);
    root->right = constructFromPrePost(pre_m, pre_r, post_m, post_r);
    return root;
  }
};
