/*
huahua use pq/heap
Runtime: 284 ms, faster than 88.61% of C++ online submissions for Maximum Frequency Stack.
Memory Usage: 66.7 MB, less than 100.00% of C++ online submissions for Maximum Frequency Stack.


*/
class FreqStack {
public:
  FreqStack() {}
 
  void push(int x) {    
    int key = (++f_[x] << 16) | (++seq_);
    q_.emplace(key, x);
  }
 
  int pop() {
    int x = q_.top().second; q_.pop();    
    if (--f_[x] == 0)
      f_.erase(x);
    return x;
  }
private:
  int seq_ = 0;
  unordered_map<int, int> f_; // {x -> freq}
  priority_queue<pair<int, int>> q_; // {freq | seq_, x}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
