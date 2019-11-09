//grandyang idea1,
//runtime 70ms, faster than 97%, mem less than 100%
class Logger {

    /** Initialize your data structure here. */
    public Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    public boolean shouldPrintMessage(int timestamp, String message) {
        if (!m.containsKey(message)) {
            m.put(message, timestamp);
            return true;
        }
        if (timestamp - m.get(message) >= 10) {
            m.put(message, timestamp);
            return true;
        }
        // <= 10
        return false;
    }
    
    Map<String,Integer> m = new HashMap<>();
    
}

//grandyang idea2, shaun java code
//runtime 71ms, faster than 86%, mem less than 100%
public class Logger2 {

    public Logger2() {}
    
    public boolean shouldPrintMessage(int timestamp, String message) {
        if (m.containsKey(message) && timestamp < m.get(message)) return false;
        m.put(message, timestamp + 10);
        return true;
    }

    private Map<String,Integer> m = new HashMap<>();
    
};


/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * boolean param_1 = obj.shouldPrintMessage(timestamp,message);
 */

