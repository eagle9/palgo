//brute force, TLE
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i+1; j < s.size(); ++j) {
                //substring i to j
                if (isValid(s.substr(i,j-i+1))) maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
private:
    bool isValid(string s) {
        stack<char> st;
        for (char ch: s) {
            if (ch == '(') st.push(ch);
            else {
                //ch == )
                if (st.empty()) return false; //no match for ) empty stack
                if (st.top() == '(') st.pop(); //match found
                else return false; //no match for ) stack top not ( 
            }
        }
        return st.empty();
    }
};
