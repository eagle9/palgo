

//gy and shaun string and stack idea, tag open and close, natural to use stack
// cutting: use stack to check tag open and close
//  challenge is to read the lengthy problem statement and catch all the details about cdata, valid tag name, etc. 
// familiar with substr(start, len),  string.find("sub", starting_from_index)
//runtime 1ms, faster than 100%, mem less than 100%

//shaun translate to java, wrong answer, to figure out later
//figured out, c++ str1 == str2,   java str1.equals(str2)
/// str.substr(start, len) ----- java str.substring(start, start+len) and make sure start+len not out of bound
// find(sub, from_index) ----- indexOf(sub, from_index)
// s[i]   ---- s.charAt(i)
// stack<string> --- Stack<String>
// stack.empty() --- stack.isEmpty()
// string.size() ---- string.length()
class Solution {
public boolean isValid(String code) {
        Stack<String> st = new Stack<>();
        
        for (int i = 0; i < code.length(); ++i) {
            if (i > 0 && st.isEmpty()) return false;
            //detect cdata tag        i       . j -- j is right after [ 
            //c++ code.substr(i,9)
            if (i+9 <= code.length() && code.substring(i, i+9).equals("<![CDATA[")) {
                int j = i + 9;
                //c++: i = code.find("]]>", j); //find substr >= j index
                i = code.indexOf("]]>", j); 
                if (i < 0) return false;
                //]]>
                //i
                i += 2;
            } 
            //look for closing tag
            //c++: else if (code.substr(i, 2) == "</") {
            else if (code.substring(i,i+2).equals("</")){
                int j = i + 2;
                //look for tag end
                //c++: i = code.find(">", j);
                i = code.indexOf(">", j);
                if (i < 0) return false;
                //string tag = code.substr(j, i - j);
                String tag = code.substring(j,i);
                //closing is not matched by an earlier openning tag
                //if (st.empty() || st.top() != tag) return false;
                if (st.isEmpty() || !st.peek().equals(tag)) return false;
                //closing tag matched to an opening tag top of the stack
                st.pop();
            } 
            //look for opening tag
            //else if (code.substr(i, 1) == "<") {
            else if (code.substring(i, i+1).equals("<")) {
                int j = i + 1;
                //i = code.find(">", j);
                i = code.indexOf(">",j);
                //tag not no end, or tag name is empty or more than 9 chars, invalid
                if (i < 0 || i == j || i - j > 9) return false;
                //tag name chars from j to i, all chars should be uppercase
                for (int k = j; k < i; ++k) {
                    //if (code[k] < 'A' || code[k] > 'Z') return false;
                    if (code.charAt(k) < 'A' || code.charAt(k) > 'Z') return false;
                }
                //enter the valid tag name into the stack
                //string tag = code.substr(j, i - j);
                String tag = code.substring(j, i);
                st.push(tag);
            }
        }
        //done with all chars, the stack should be empty to be valid, otherwise invalid
        //return st.empty();
        return st.isEmpty();
    }
};
