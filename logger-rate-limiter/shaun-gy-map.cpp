//grandyang idea1
//shaun coded from the idea, runtime 96ms, faster than 62%, mem less than 100%
class Logger {
public:
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (!m.count(message)) {
            m[message] = timestamp;
            return true;
        }
        //message in m and within 10 seconds
        if (m[message] > timestamp - 10) return false;
        
        m[message] = timestamp;
        return true;
    }

private:
    unordered_map<string, int> m;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
