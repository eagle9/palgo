//hua idea combine maxHeap of pair(key,x) and hash table
//very natural
//shaun read, understand and rewrite
//runtime 256ms, faster than 64%, mem less than 99%
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
  priority_queue<pair<int, int>> maxHeap; // {freq | seq, x}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
