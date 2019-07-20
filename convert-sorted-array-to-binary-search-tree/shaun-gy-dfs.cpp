/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun's idea, observe from the example, find the mid index number and take it as root
//then the subarray before the mid is sorted, and subarray after the mid, smaller problem but similar
//how to ensure the bst is balanced? mid point will will help with being balanced
//runtime 16ms, faster than 90%, mem less than 82%
//shaun idea with the mid index number as root, then recur first part subarray and second part subarray, details upon grandyang hint, accepted after 1 bug fix 

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    
private:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        int mid = left + (right - left)/2;
        //TreeNode* root = new TreeNode(mid); //bug mid --> nums[mid] as the root value
        TreeNode* root = new TreeNode(nums[mid]); 
        root->left = helper(nums, left, mid-1);
        root->right= helper(nums, mid+1, right);
        return root;
    }
};
