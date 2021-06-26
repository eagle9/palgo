//shaun own try, runtime error
//to figure out
class AllOne {
private:
    struct Node {
        int value;
        unordered_set<string> keys;
    };
    //store all value->keys in dlist, order by value
    list<Node> buckets;
    unordered_map<string,list<Node>::iterator> m;
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        //check for new key
        if (!m.count(key)) {
            //new key found, value = 1
            if (buckets.empty() || buckets.front().value != 1) {
                //empty buckets or no bucket for value =1 yet
                buckets.push_front({1, {key}});
                
            }else { //not empty and bucket for val = 1 exists
                buckets.front().keys.insert(key);
            }
            m[key] = buckets.begin();
            return;
        }
        //else keys already found, increase its value
        
        auto it = m[key];
        //check if bucket exists for oldValue + 1
        auto nit = next(m[key]);
        //
        if (nit == buckets.end() || nit->value != it->value +1) {
            //create a new bucket
            auto newit = buckets.insert(nit, {it->value+1, {key}});
            m[key] = newit;
            return;
        }
        //now buckets not empty and nit->value == it->value+1
        //key now in value+1 bucket
        //gone from value bucket
        nit->keys.insert(key);
        it->keys.erase(key);
        m[key] = nit;
        return;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!m.count(key)) return; //key not found, no action 
        auto it = m[key];
        if (it->value == 1) {
            //erase the key from the bucket
            it->keys.erase(key);
            if (it->keys.empty()) buckets.erase(it);
            m.erase(key);
            return;
        }
        //now it->value > 1
        auto previt = prev(m[key]);
        //if (buckets.empty() && previt->value != it->value -1) {
        if (it == buckets.begin() && previt->value != it->value-1) {
            //create a bucket for value-1
            auto newit = buckets.insert(previt, {it->value-1,{key}});
            m[key] = newit;
            return;
        }
        //now buckets not empty and previt->value == value-1
        previt->keys.insert(key);
        it->keys.erase(key);
        m[key] = previt;
        return;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets.empty()? "": *(buckets.back().keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty()?"": *(buckets.front().keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
