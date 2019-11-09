//jiadai c++ 
class RateLimiter {
public:
    /**
     * @param timestamp the current timestamp
     * @param event the string to distinct different event
     * @param rate the format is [integer]/[s/m/h/d]
     * @param increment whether we should increase the counter
     * @return true or false to indicate the event is limited or not
     */
    bool isRatelimited(int timestamp, string& event, string& rate, bool increment) {
        // Write your code here
        char unit = rate.back();
        int limit = stoi(rate.substr(0, rate.size() - 2));
        int duration = 1;
        if (unit == 'm') {
            duration *= 60;
        }
        else if (unit == 'h') {
            duration *= 60 * 60;
        }
        else if (unit == 'd') {
            duration *= 60 * 60 * 24;
        }
        
        int startTime = timestamp - duration + 1;
        int count = Count(event, startTime);
		//if increment is flagged and count < limit, record the event
        if (increment && count < limit) {
            table[event].push_back(timestamp);
        }
        
        return count >= limit;
    }
    
private:
    unordered_map<string, vector<int>> table;
	//find event's list of timestamps, count how many >= startTime
    int Count(string& event, int startTime) {
        vector<int>& time = table[event];
        if (time.size() == 0) {
            return 0;
        }

		//find first index start >= startTime
        int start = 0, end = time.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (time[mid] >= startTime) {
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }
        //start + 1 == end now 
        if (time[start] >= startTime) {
            return time.size() - start;
        }
        else if (time[end] >= startTime) {
            return time.size() - end;
        }
        else { //not found
            return 0;
        }
    }
};

