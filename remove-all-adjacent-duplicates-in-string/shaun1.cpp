//shaun's own idea with stack hint
//runtime 576ms, faster than 5%, mem less than 100%
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (char c: S) {
            if (st.empty() || st.top() != c) st.push(c);
            else {
                //st not empty and top() == c
                while (!st.empty() && st.top() == c) st.pop();
            }
            
        }
        vector<char> res;
        while (!st.empty()) {
            res.insert(res.begin(),st.top());
            st.pop();
        }
        return string(res.begin(), res.end());
    }
};

//shaun's improvement with vector used as a stack
//runtime 24ms, faster than 68%, mem less than 100%
class Solution2 {
public:
    string removeDuplicates(string S) {
        vector<char> st;
        for (char c: S) {
            if (st.empty() || st.back() != c) st.push_back(c);
            else {
                //st not empty and top() == c
                while (!st.empty() && st.back() == c) st.pop_back();
            }
            
        }
        
        return string(st.begin(), st.end());
    }
};
