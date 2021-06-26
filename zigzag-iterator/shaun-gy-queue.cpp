//shaun learned grandyang q idea, can be extended to k vectors
//runtime 20ms, faster than 99%, mem less than 7%
//also tested me how to design a customized class/struct with constructors
//use of references to save time
struct entry{
    vector<int>& v;
    int cur, end;
    entry(vector<int>& v, int cur, int end): v(v), cur(cur), end(end) {};
};
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) q.push(entry(v1,0, v1.size()));
        if (!v2.empty()) q.push(entry(v2,0, v2.size()));
    }

    int next() {
        auto t = q.front(); q.pop();
        int res;
        if (t.cur < t.end) res = t.v[t.cur];
        if (t.cur + 1 < t.end) q.push(entry(t.v, t.cur+1, t.end));
        return res;
    }

    bool hasNext() {
        return !q.empty();
    }
private:
    queue<entry> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
