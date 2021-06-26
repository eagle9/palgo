//shaun rewrite in java from the idea 
// java HashMap, get value for a key, getOrDefault, putIfAbsent
// runtime 89ms, faster than 77%, mem less than 97%
class FreqStack {
    private Map<Integer,Integer> freq; //number to its frequency
    private Map<Integer,Stack<Integer>> group;// freq to its Stack<I>
    private int maxFreq;
    
    public FreqStack() {
        freq = new HashMap<>();
        group = new HashMap<>();
        maxFreq = 0;
    }
    
    //update freq and maxFreq, push into f related stack
    public void push(int x) {
        //get exisiting x's freq before this copy of x
        int f = freq.getOrDefault(x,0);
        f++;
        freq.put(x,f);
        if (f > maxFreq) maxFreq = f;
        
        group.putIfAbsent(f, new Stack<>());
        group.get(f).push(x); //what if f is not a key yet
        
        //group.computeIfAbsent(f, z-> new Stack()).push(x); //works
    }
    
    //pop from maxFreq related stack
    //update freq and maxFreq
    public int pop() {
        Stack<Integer> st = group.get(maxFreq);
        int x = st.pop();
        if (st.isEmpty()) maxFreq--;
        
        freq.put(x, freq.get(x)-1);
        
        return x;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
