//lt cutting: freq to Stack<Integer>, each frequency has its own stack
//  update freq and maxfreq
//shaun code in c++ from lt java code idea
//runtime 236ms, faster than 94%, mem less than 92%
class FreqStack {
private:
    unordered_map<int,int> freq; //number to frequency
    unordered_map<int,stack<int>> group; // each freq has its own stack 
    int maxfreq;
public:
    FreqStack() {
        maxfreq = 0;
    }
    
    //update freq and maxfreq, push into x's freq related stack
    void push(int x) {
        freq[x]++;
        int f = freq[x];
        if (f > maxfreq) maxfreq = f;
        
        group[f].push(x);
    }
    
    //pop from stack that related to maxfreq
    //update freq, if maxfreq stack empty, maxfreq--
    int pop() {
        int x = group[maxfreq].top(); group[maxfreq].pop();
        freq[x]--;
        if (group[maxfreq].empty()) maxfreq--;
        return x;
    }
};



/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
