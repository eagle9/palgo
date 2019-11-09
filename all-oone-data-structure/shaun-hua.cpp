//hua's idea, buse list<Node>, struct Node {int value; unordered_set<string> keys;}
// unodered_map<string,list<Node>::iterator>
// min value node at front, max value node at the back
//runtime 48ms, faster than 84%, mem less than 100%
class AllOne {
public:
  /** Initialize your data structure here. */
  AllOne() {}
 
  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
  void inc(string key) {
    auto ip = m_.find(key); //iterator of kv pair
    
    if (ip == m_.end()) { //new key, value = 1
      if (l_.empty() || l_.front().value != 1) //create new node for value=1
        l_.push_front({1, {key}});
      else
        l_.front().keys.insert(key);
      m_[key] = l_.begin();
      return;
    }
    
    auto curit = ip->second;
    
    auto nit = next(curit);
    if (nit == l_.end() || nit->value != curit->value + 1) //need to create new node at nit
      nit = l_.insert(nit, {curit->value + 1, {}}); //insert at nit
    
    //insert key to nit node, update m[key] and remove key from curit node
    nit->keys.insert(key);
    m_[key] = nit;
    
    remove(curit, key);
  }
 
  /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
  void dec(string key) {
    auto ip = m_.find(key);
    if (ip == m_.end()) return;
    
    auto it = ip->second;
        
    if (it->value > 1) {
      auto previt = prev(it);
      if (it == l_.begin() || previt->value != it->value - 1) //need to create node,  between previt and it,  previt new_node it
        previt = l_.insert(it, {it->value - 1, {}});
      previt->keys.insert(key);
      m_[key] = previt;
    } else {
      // value == 1, remove from the data structure, no need to place the key in a node value =0
      m_.erase(key);
    }
    //remove key from current node
    remove(it, key);    
  }
 
  /** Returns one of the keys with maximal value. */
  string getMaxKey() {
    return l_.empty() ? "" : *l_.back().keys.cbegin();
  }
 
  /** Returns one of the keys with Minimal value. */
  string getMinKey() {
    return l_.empty() ? "" : *l_.front().keys.cbegin();
  }
private:
  struct Node {  
    int value;
    unordered_set<string> keys;
  };
  
  list<Node> l_;
  unordered_map<string, list<Node>::iterator> m_;
  
  // Remove from old node.
  void remove(list<Node>::iterator it, const string& key) {
    it->keys.erase(key);
    if (it->keys.empty())
      l_.erase(it);
  }
};
