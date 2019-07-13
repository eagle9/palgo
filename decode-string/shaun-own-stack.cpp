//shaun's own idea and code, accepted after fixes
//fix 1:   repetition number can be 100, not just single digit number
//fix 2:  c++ init string with length
//fix 3: some typos
//runtime 4ms, faster than 100%, mem less than 95%
//the breakthough is made to run your idea with some examples, think with force and clarity
//cutting ---- use stack to process nested structure, push, then check top, pop it, process it, then push back, one tricky details is to process the number that could be multiple chars
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                st.push(c);
            }else if (c == '[') {
                st.push(c);
            }else if (isalpha(c)) {
                st.push(c);
            }else if (c == ']') { 
                vector<char> temp;
                //pop chars till first previous [
                while (!st.empty() && st.top() != '[') {
                    char c2 = st.top(); st.pop();
                    temp.insert(temp.begin(),c2);
                }
                //st.top == '[' now, pop it
                st.pop();
                
                //now look for the number(reps)
                int n = 0, base = 1;
                while (!st.empty() && isdigit(st.top())) {
                    int digit = st.top() - '0'; st.pop(); 
                    n += digit*base;
                    base*=10;
                }
                
                //push vector<char> temp back to stack n reps
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < temp.size(); ++j) {
                        st.push(temp[j]);
                    }
                }
            }
        }
        int n = st.size();
        string res(n,'x');
        int i = n-1;
        while (!st.empty()) {
            res[i--] = st.top(); st.pop();
        }
        return res;

    }
};
