/*
huahua, to understand
Runtime: 444 ms, faster than 98.92% of C++ online submissions for Time Based Key-Value Store.
Memory Usage: 136.8 MB, less than 65.14% of C++ online submissions for Time Based Key-Value Store.

*/
class TimeMap {
public:
  /** Initialize your data structure here. */
  TimeMap() {}
 
  void set(string key, string value, int timestamp) {
    s_[key].emplace(timestamp, std::move(value));
  }
 
  string get(string key, int timestamp) {
    auto m = s_.find(key);
    if (m == s_.end()) return "";    
    auto it = m->second.upper_bound(timestamp);
    if (it == begin(m->second)) return "";
    return prev(it)->second;
  }
private:
  unordered_map<string, map<int, string>> s_; 
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
