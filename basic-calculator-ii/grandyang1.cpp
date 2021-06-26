/*
Runtime: 16 ms, faster than 82.81% of C++ online submissions for Basic Calculator II.
Memory Usage: 10.7 MB, less than 100.00% of C++ online submissions for Basic Calculator II.
grandyang idea1

*/
class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, n = s.size();
        char op = '+';
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0') {
                num = num * 10 + (s[i] - '0');
            }
            if ((s[i] < '0' && s[i] != ' ') || i == n - 1) {
                if (op == '+') st.push(num);
                if (op == '-') st.push(-num);
                if (op == '*' || op == '/') {
                    int tmp = (op == '*') ? st.top() * num : st.top() / num;
                    st.pop();
                    st.push(tmp);
                }
                op = s[i];
                num = 0;
            } 
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
