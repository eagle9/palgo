/*
grandyang two stack idea, shaun adapted to java code, beats 95% runtime 3ms
*/
class Solution {
    public String decodeString(String s) {
        Stack<Integer> s_num = new Stack<>();
        Stack<StringBuilder> s_str = new Stack<>();
        int cnt = 0;
        StringBuilder t = new StringBuilder();
        for (char c: s.toCharArray()) {
            //c is digit, figure out cnt reps
            if (c >= '0' && c <= '9') {
                cnt = 10* cnt + (c - '0');
            }else if (c == '[') { //left bracket
                s_num.push(cnt);
                s_str.push(t);
                cnt = 0; 
                t = new StringBuilder();
            }else if (c == ']') {
                int k = s_num.pop();
                StringBuilder sb = s_str.pop();
                for (int j = 0; j < k; j++) {
                    sb.append(t);
                }
                t = sb;
            }else {
                t.append(c);
            }
        }
        return s_str.isEmpty()?t.toString():s_str.peek().toString();
    }
}

/*
//grandyang two stack, beats 100%
class Solution {
public:
    string decodeString(string s) {
        string res = "", t = "";
        stack<int> s_num;
        stack<string> s_str;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                cnt = 10 * cnt + s[i] - '0';
            } else if (s[i] == '[') {
                s_num.push(cnt);
                s_str.push(t);
                cnt = 0; t.clear();
            } else if (s[i] == ']') {
                int k = s_num.top(); s_num.pop();
                for (int j = 0; j < k; ++j) s_str.top() += t;
                t = s_str.top(); s_str.pop();
            } else {
                t += s[i];
            }
        }
        return s_str.empty() ? t : s_str.top();
    }
};
*/
