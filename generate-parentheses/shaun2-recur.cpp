//jz idea, shaun coded from memorized idea
//first sub wrong, second sub accepted
//runtime 4ms, faster than 97.54%, mem less than 25%
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("", n,n, res);
        return res;
    }
private:
    //left  -- number of ( to add
    //right -- number of ) to add
    void helper(string cur, int left, int right, vector<string>& res) {
        if (left == 0 && right == 0) {
            res.push_back(cur);
            return;
        }
        if (left > 0) {
            //cur += "("; ===> wrong answer
            helper(cur+"(", left-1, right, res);
        }
        if (right > 0 && left < right) {
            //cur += ")";
            helper(cur+")", left, right-1, res);
        }
    }
};

/*
idea forming, cutting angle,  cursor recursion, add left and right one by one
my init idea n to n-1 uses too much space
()
()() --- ()()
(())

()()
====
()()() -- ()()()
(()())

(())
====
(())()
()(())
((()))
*/

