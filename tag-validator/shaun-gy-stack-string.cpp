//gy and shaun string and stack idea, tag open and close, natural to use stack
// cutting: use stack to check tag open and close
//  challenge is to read the lengthy problem statement and catch all the details about cdata, valid tag name, etc. 
// familiar with substr(start, len),  string.find("sub", starting_from_index)
//runtime 4ms, faster than 72%, mem less than 100%
class Solution {
public:
    bool isValid(string code) {
        stack<string> st;
        for (int i = 0; i < code.size(); ++i) {
            if (i > 0 && st.empty()) return false;
            //detect cdata tag        i       . j -- j is right after [ 
            if (code.substr(i, 9) == "<![CDATA[") {
                int j = i + 9;
                i = code.find("]]>", j); //find substr >= j index
                if (i < 0) return false;
                //]]>
                //i
                i += 2;
            } 
            //look for closing tag
            else if (code.substr(i, 2) == "</") {
                int j = i + 2;
                //look for tag end
                i = code.find(">", j);
                if (i < 0) return false;
                string tag = code.substr(j, i - j);
                //closing is not matched by an earlier openning tag
                if (st.empty() || st.top() != tag) return false;
                //closing tag matched to an opening tag top of the stack
                st.pop();
            } 
            //look for opening tag
            else if (code.substr(i, 1) == "<") {
                int j = i + 1;
                i = code.find(">", j);
                //tag not no end, or tag name is empty or more than 9 chars, invalid
                if (i < 0 || i == j || i - j > 9) return false;
                //tag name chars from j to i, all chars should be uppercase
                for (int k = j; k < i; ++k) {
                    if (code[k] < 'A' || code[k] > 'Z') return false;
                }
                //enter the valid tag name into the stack
                string tag = code.substr(j, i - j);
                st.push(tag);
            }
        }
        //done with all chars, the stack should be empty to be valid, otherwise invalid
        return st.empty();
    }
};
