//grandyang c++, beats 21% at leetcode
//not quite understand yet
class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (m.count(key) == 0) return -1;
        freq[m[key].second].erase(iter[key]);
        ++m[key].second;
        freq[m[key].second].push_back(key);
        iter[key] = --freq[m[key].second].end();
        if (freq[minFreq].size() == 0) ++minFreq;
        return m[key].first;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;
        if (get(key) != -1) {
            m[key].first = value;
            return;
        }
        if (m.size() >= cap) {
            m.erase(freq[minFreq].front());
            iter.erase(freq[minFreq].front());
            freq[minFreq].pop_front();
        }
        m[key] = {value, 1};
        freq[1].push_back(key);
        iter[key] = --freq[1].end();
        minFreq = 1;
    }

private:
    
    //哈希表m来记录当前数据{key, value}和其出现次数之间的映射，
    unordered_map<int, pair<int, int>> m;
    //这样还不够，为了方便操作，我们需要把相同频率的key都放到一个list中，那么需要另一个哈希表freq来建立频率和一个里面所有key都是当前频率的list之间的映射
    unordered_map<int, list<int>> freq;
    //由于题目中要我们在O(1)的时间内完成操作了，为了快速的定位freq中key的位置，我们再用一个哈希表iter来建立key和freq中key的位置之间的映射。
    unordered_map<int, list<int>::iterator> iter;
    //最后当然我们还需要两个变量cap和minFreq，分别来保存cache的大小，和当前最小的频率。
    int cap, minFreq;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
