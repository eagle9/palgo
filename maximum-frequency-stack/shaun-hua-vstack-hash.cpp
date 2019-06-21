// hua idea with bucket of stack, and hashtable
//store frequency with hashtable is natural
// store number according to its frequency, each frequency has a bucket, the bucket is a stack

// Running time: 224 ms, faster than 96.70%, mem less than 13%
class FreqStack {
public:
  FreqStack() {}
 
  
    void push(int x) {
        freq_[x]++;  
        int freq = freq_[x];    
        if (stacks_.size() < freq) stacks_.push_back({});
        stacks_[freq - 1].push(x);
    }
    
    int pop() {  
        
        /*stack<int> last = stacks_.back(); // bug can not store vector.back()
        int x = last.top();
        last.pop();
        if (last.empty()) stacks_.pop_back();*/
        
        /*int n = stacks_.size();   //working
        int x = stacks_[n-1].top(); stacks_[n-1].pop();
        if (stacks_[n-1].empty()) stacks_.pop_back();  */
        auto& last = stacks_.back(); //back() return reference //bug auto last won't work, auto& works
        int x = last.top(); last.pop();
        if (last.empty()) stacks_.pop_back();
        /*hua code
        int x = stacks_.back().top();    
        stacks_.back().pop();
        if (stacks_.back().empty())
            stacks_.pop_back();   */
        
        
        freq_[x]--;
        if (freq_[x] == 0) freq_.erase(x);
        
        /*
        auto it = freq_.find(x);
        if (!(--it->second)) freq_.erase(it);*/
        return x;
        
    }
    
  int pop000() {  //hua code   
    int x = stacks_.back().top();    
    stacks_.back().pop();
    if (stacks_.back().empty())
      stacks_.pop_back();
    auto it = freq_.find(x);
    if (!(--it->second))
      freq_.erase(it);
    return x;
  }
private:  
  vector<stack<int>> stacks_;
  unordered_map<int, int> freq_;
};
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
