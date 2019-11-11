/*
huahua, shaun read and has understood
runtime 404ms, faster than 62%, mem less than 100%
*/
class TimeMap {
public:
  /** Initialize your data structure here. */
  TimeMap() {}
 
  void set(string key, string value, int timestamp) {
    //s_[key].emplace(timestamp, value);
      s_[key][timestamp] = value;
  }
 
  string get(string key, int timestamp) {
    auto m = s_.find(key);
    if (m == s_.end()) return "";
    //find first it > timestamp, we want the one before it, which is last <=, or max & <= timestamp
    auto it = m->second.upper_bound(timestamp);
    //make sure we can get prev, if begin
    //if (it == begin(m->second)) return "";
    if (it == m->second.begin()) return "";
    return prev(it)->second;
  }
private:
    //map from key to ordered_map
  unordered_map<string, map<int, string>> s_; 
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
