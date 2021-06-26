//grandyang idea2 using stack
//runtime 13ms, faster than 83%
public class Solution {
    public String simplifyPath(String path) {
        Stack<String> s = new Stack<>();
        String[] p = path.split("/");
		//.  .. ""(from //) letters
        for (String t : p) {
            if (!s.isEmpty() && t.equals("..")) {
                s.pop();
            } else if (!t.equals(".") && !t.equals("") && !t.equals("..")) {
                s.push(t);
            }
        }
		//stack to list
        List<String> list = new ArrayList(s);
		//String.join function 
        return "/" + String.join("/", list);
    }
}
