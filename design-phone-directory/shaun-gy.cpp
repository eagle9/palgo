//runtime 56ms, faster than 54%, mem less than 100%
//gy using hash set and queue
class PhoneDirectory {
public:
    PhoneDirectory(int maxNumbers) {
        mx = maxNumbers;
        for (int i = 0; i < maxNumbers; ++i) q.push(i);
    }
    int get() {
        if (q.empty()) return -1;
        int num = q.front(); q.pop();
        used.insert(num);
        return num;
    }
    bool check(int number) {
        return !used.count(number);
    }
    void release(int number) {
        if (!used.count(number)) return;
        used.erase(number);
        q.push(number);
    }
    
private:
    int mx;
    queue<int> q;
    unordered_set<int> used;
};
/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
