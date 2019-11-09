//hua idea combine maxHeap of pair(key,x) and hash table
//very natural
//cutting:
//according problem requirements:
// top --- max frequency, if tied, most recent pushed (use seq number)
//  so max freq and seq, at top, combine freq and seq, pair with the number
//  turns into a maxHeap
//shaun read, understand and rewrite
//runtime 252ms, faster than 45%, mem less than 99%
class FreqStack {
public:
  FreqStack() {}

    void push(int x) {
        //key first 2 bytes freq, last 2 bytes seq
        int key = (++freq[x] << 16) | (++seq);
        maxHeap.emplace(key, x); //maxHeap of pair key x
    }

    int pop() {
        int x = maxHeap.top().second; maxHeap.pop();
        if (--freq[x] == 0) freq.erase(x);
        return x;
    }
private:
    int seq = 0;
    unordered_map<int, int> freq; // {x -> freq}
    //max freq and seq at the top, pair with the number
    priority_queue<pair<int, int>> maxHeap; // {freq | seq, x}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
