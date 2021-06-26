/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 idea: find ( in string, if not found, entire string is a number
 if found,  the number is represented with string substr(0,found)
 create TreeNode with the number
 start = found
 loop from start to end of string, 
   if (, count++, ) count--, 
   if count ==0 && start == found 
   substr(found, i-1 - (start+1)+1 = i - found-1
   start = i+1
    f       i
   4(2(3)(1))
   if (start == found) left subtree
   if ()
   left or right subtree? 
 
 grandyang idea, using count++/-- to match parenthesis
 runtime 44ms, faster than 44%, mem less than 40%
 */
class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return NULL;
        auto found = s.find('(');
        int val = (found == string::npos) ? stoi(s) : stoi(s.substr(0, found));
        TreeNode *cur = new TreeNode(val);
        if (found == string::npos) return cur;
        int start = found, cnt = 0;
        for (int i = start; i < s.size(); ++i) {
            if (s[i] == '(') ++cnt;
            else if (s[i] == ')') --cnt;
            if (cnt == 0 && start == found) {
                cur->left = str2tree(s.substr(start + 1, i - start - 1));
                start = i + 1;
            } else if (cnt == 0) {
                cur->right = str2tree(s.substr(start + 1, i - start - 1));
            }
        }
        return cur;
    }
};

