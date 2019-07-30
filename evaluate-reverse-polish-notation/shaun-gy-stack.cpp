//grandyang idea1, runtime 16ms, faster than 100%
//cutting: obivious and straightforward stack application
//runtime 12ms, faster than 91%, mem less than 63%
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //if (tokens.size() == 1) return stoi(tokens[0]); //skip this line accepted too
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                st.push(stoi(tokens[i]));
            } else {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                
                if (tokens[i] == "+") st.push(num1 + num2);
                if (tokens[i] == "-") st.push(num1 - num2);
                if (tokens[i] == "*") st.push(num1 * num2);
                if (tokens[i] == "/") st.push(num1 / num2);
                
                /*
                //bug, switch quantity not an integer
                switch (tokens[i]) {
                    case "+": st.push(num1+ num2); break;
                    case "-": st.push(num1 - num2); break;
                    case "*": st.push(num1 * num2); break;
                    case "/": st.push(num1 /num2); break;
                }*/
            }
        }
        return st.top();
    }
};
