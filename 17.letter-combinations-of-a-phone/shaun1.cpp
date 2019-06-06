//shaun own idea, i tried to use cursor style recursion, accepted after fixing 3 bugs
//runtime 0ms, faster than 100%, mem less than 34%
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        m['2'] = {'a','b','c'};
        m['3'] = {'d','e','f'};
        m['4'] = {'g','h','i'};
        m['5'] = {'j','k','l'};
        m['6'] = {'m','n','o'};
        m['7'] = {'p','q','r','s'};
        m['8'] = {'t','u','v'};
        m['9'] = {'w','x','y','z'};
        int n = digits.size();
        
        vector<string> res;
        if (digits.empty()) return res; //bug 3, should add this line for the empty corner case
        
        helper(digits, "", 0, n, res);
        return res;
    }
    
private:
    void helper(string digits, string cur, int index, int n, vector<string>& res) {
        if (index == n) {
            res.push_back(cur);
            return;
        }
        char digit = digits[index];
        for (char letter: m[digit]) {
            cur.push_back(letter);
            //cur.append(letter) //bug 2, no string::append function
            helper(digits, cur, index+1, n, res);
            cur.pop_back();
        }
    }
    unordered_map<char,vector<char>> m;
    //m['2'] = {'a','b','c'} //bug 1  you can not write assignment here
};
