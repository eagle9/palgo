/*
shaun first try accepted, luckily very natural extensible from ii solution with counting
runtime 120ms, faster than 87%
*/
class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        freq[start]++;
        freq[end]--;
        int count = 0;
        int mx = 0;
        for (auto kv: freq) {
            count+= kv.second;
            if (count > mx) mx = count;
        }
        return mx;
        
    }
private:
    map<int,int> freq; //sorted key
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
