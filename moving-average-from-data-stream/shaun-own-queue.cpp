//shaun own idea and code, add one line (count-- inside if q.size() > size) after manual testing, accepted first sub, runtime 28ms, faster than 96%, mem less than 77%
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sum = 0;
        count = 0;
        this->size = size;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        count++;
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
            count--;
        }
        return sum/count;
        
    }
private:
    queue<int> q;
    double sum;
    int size,count;
    
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
