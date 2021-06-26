//shaun origin idea, accepted second sub, need proof read and test before submission
//runtime 4ms, faster than 92%, mem less than 59%
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> st;
        for (char ch: S) {
            if (st.empty() || !canReduce(st,ch) ) st.push(ch);
            else st.pop();
        }
        return st.size();
    }
private:
    //can reduce ?
    bool canReduce(stack<char>& st, char ch) {
        if (!st.empty() && st.top() == '(' && ch == ')') return true;
        return false;
    }
};
