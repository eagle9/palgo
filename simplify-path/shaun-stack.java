class Solution {
    public String simplifyPath(String path) {
        Stack<String> st = new Stack<>();
        String [] tokens = path.split("/");
        for (String token: tokens) {
            //case 1 and 2
            if (token.equals(".") || token.equals("")) continue;
            //case 3 token == ..
            if (token.equals("..")) { 
                if (!st.isEmpty()) st.pop();
                continue;
            }
            
            //case 4 valid folder name
            st.push(token);
        }
        
        return "/" + String.join("/", new ArrayList<String>(st));
        
        /*
        if (st.isEmpty()) return "/"; //bug 1 .. return ""
        String ans = "";
        while (!st.isEmpty()) {
            String folder_name = st.pop();
            ans = "/" + folder_name + ans;
        }
        return ans;
        */
    }
}

//shaun with split and stack
//cutting, split with /, tokenizer from string stream, use example, you will find once a token is .., pop the stack.  end up with simplifed folder-names stored in stack, then pop all out, last insert at front
//runtime 8ms, faster than 88.70%, mem less than 9%
