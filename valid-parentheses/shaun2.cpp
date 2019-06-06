//shaun's own idea, first sub wrong answer failing case "(])"
//modified after for this failed case, accepted
//runtime 4ms, faster than 93%, mem less than 69%
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch: s) {
            if (ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else {
                if (st.empty()) return false;
                //can match
                if ((ch == ')' && st.top() == '(') || 
                    (ch == ']' && st.top() == '[') || 
                    (ch == '}' && st.top() == '{')) st.pop();
                //else st.push(ch); // first fix
                else return false; //okay too
            }
        }
        return st.empty();
    }
};
