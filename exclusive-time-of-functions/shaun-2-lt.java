class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        Stack<Integer> st = new Stack<>();
        int [] res = new int[n];
        if (logs.isEmpty()) return res;
        
        String [] s = logs.get(0).split(":");
        int id = Integer.valueOf(s[0]);
        int ts = Integer.valueOf(s[2]);
        st.push(id);
        int prev = ts;
        for (int i = 1; i < logs.size(); i++) {
            s = logs.get(i).split(":");
            id = Integer.valueOf(s[0]);
            ts = Integer.valueOf(s[2]);
            if (s[1].equals("start")) {
                if (!st.isEmpty())
                    res[st.peek()] += ts - prev;
                st.push(id);
                prev = ts;
            }else { //end at ts
                res[st.peek()] += ts - prev + 1; //use example
                st.pop();
                prev = ts +1; //use example to verify
                
            }
        }
        return res;
    }
}
