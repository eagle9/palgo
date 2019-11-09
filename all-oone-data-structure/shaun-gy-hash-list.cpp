/*
struct Bucket{int value; unordered_set<string> keys;};

list<Bucket> buckets;
  list ordered by Bucket.value, max at the front, min value at the back
  
unordered_map<string, list<Bucket>::iterator>

buckets ordered by Bucket.value， max value at the front, min value at the back

given a key, find it it value --> keys
  dec the key's value, the key goes to prev bucket(value-1), gone from current bucket
  inc the key's value, the key gone current current bucket, into next bucket(value+1)
  prev or next bucket might not exist, so in case not exist, create the bucket and insert orderly

better draw some example list and hash
shaun read and understand, next step to code after 3 days

runtime 48ms, faster than 83%, mem less than 100%
*/
class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {}
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!m.count(key)) { //new key, value = 1
            //buckets empty, insert at the end
            if (buckets.empty() || buckets.back().val != 1) {
                /*auto newBucket =*/ buckets.insert(buckets.end(), {1, {key}});
                m[key] = --buckets.end(); // = newBucket works too
            } else { //buckets not empty and buckets.back().val == 1
                auto newBucket = --buckets.end();
                newBucket->keys.insert(key);
                m[key] = newBucket;
            }
        } else { //key already in the data structure
            auto curBucket = m[key], nextBucket = (--m[key]);
            //if need create new bucket
            if (nextBucket == buckets.end() || nextBucket->val != curBucket->val + 1) {
                auto newBucket = buckets.insert(curBucket, {curBucket->val + 1, {key}});
                m[key] = newBucket;
            } else { //nextBucket value is 1 more 
                nextBucket->keys.insert(key);
                m[key] = nextBucket;
            }
            //key gone from curBucket, now in nextBucket
            curBucket->keys.erase(key);
            if (curBucket->keys.empty()) buckets.erase(curBucket);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!m.count(key)) return;
        auto curBucket = m[key];
        if (curBucket->val == 1) {//key's value is 1, remove it from buckets
            curBucket->keys.erase(key);
            if (curBucket->keys.empty()) buckets.erase(curBucket);
            m.erase(key);
            return;
        }
        //key's value is not 1
        auto prevBucket = ++m[key];
        if (prevBucket == buckets.end() || prevBucket->val != curBucket->val - 1) {
            auto newBucket = buckets.insert(prevBucket, {curBucket->val - 1, {key}});
            m[key] = newBucket;
        } else {
            prevBucket->keys.insert(key);
            m[key] = prevBucket;
        }
        //key gone from curBucket, now in nextBucket
        curBucket->keys.erase(key);
        if (curBucket->keys.empty()) buckets.erase(curBucket);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        //return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
        return buckets.empty()? "" : *(buckets.front().keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        //return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
        return buckets.empty() ? "" : *(buckets.back().keys.begin());
    }
private:
    struct Bucket { int val; unordered_set<string> keys; };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> m;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
