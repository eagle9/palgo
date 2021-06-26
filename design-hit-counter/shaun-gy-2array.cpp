//gy use two arrays of size 300 to store timestamps and hits
//runtime 8ms, faster than 58%, mem less than 100%
//this idea can scale when there are many hits within 1 second
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        times.resize(300);
        hits.resize(300);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int idx = timestamp % 300;
        if (times[idx] != timestamp) { // times[idx] past 5 min, overwrite and set hits to 1
            times[idx] = timestamp;
            hits[idx] = 1;
        } else { //existing, increment hits
            ++hits[idx];
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int res = 0;
        for (int i = 0; i < 300; ++i) {
            if (timestamp - times[i] < 300) {
                res += hits[i];
            }
        }
        return res;
    }

private:
    vector<int> times, hits;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
