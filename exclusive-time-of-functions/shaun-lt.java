//runtime 12ms, faster than 93%, mem less than 7%
//time O(n), space O(1)
public class Solution {
    public int[] exclusiveTime(int n, List < String > logs) {
        
        Stack<Integer> stack = new Stack<>();
        int [] res = new int[n];
        
        //function_id: start|end: timestamp
        String [] s = logs.get(0).split(":");
        int id = Integer.parseInt(s[0]), ts = Integer.parseInt(s[2]);
        stack.push(id); 
        int prev = ts;
        for (int i = 1; i < logs.size(); i++) {
            s = logs.get(i).split(":");
            id = Integer.parseInt(s[0]);
            ts = Integer.parseInt(s[2]);
            if (s[1].equals("start")) {
                if (!stack.isEmpty())
                    res[stack.peek()] += ts - prev;
                stack.push(id);
                prev = ts;
            }else {
                res[stack.peek()] += ts - prev +1;
                stack.pop();
                prev = ts + 1;
            }
        }
        return res;
    }
            
}
