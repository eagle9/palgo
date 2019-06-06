//https://www.youtube.com/watch?v=r0-zx5ejdq0&t=992s 
//idea as above, shaun has understood
//less error prone that lt stack idea
//runtime 8ms, faster than 93%, mem less than 63%
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push_back(i);
            else {
                if (st.empty()) st.push_back(i); //no match
                else {
                    if (s[st.back()] == '(') st.pop_back(); //matched and reduced
                    else { // no match and pushed to stack
                        st.push_back(i);
                    }
                }
            }
        }
        st.push_back(s.size());
        //for (auto x: st) cout << x << endl;
        
        int start = -1, longest = 0;
        for (int i = 0; i < st.size(); ++i) {
            longest = max(st[i] - start-1, longest);
            start = st[i];
        }
        
        return longest; 
    }
};
