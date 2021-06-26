/*
shaun from huahua's idea, 
Runtime: 164 ms, faster than 96.17% of C++ online submissions for Find Median from Data Stream.
*/
class MedianFinder {
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left_.empty() || num <= left_.top()) {
            left_.push(num);
            
        }else { //left not empty and num > left top
            right_.push(num);
        } 
        
        //left_.size = or +1 right.size
        if (left_.size() < right_.size()) {
            left_.push(right_.top());
            right_.pop();
        } // second try add else, does not matter, later removed
        if (left_.size() == right_.size() + 2) {
            right_.push(left_.top());
            left_.pop();
            
        }
        //end up with left.size = right.size or one more
    }
    double findMedian_huahua() {
        if (left_.size() > right_.size()) {
            return static_cast<double>(left_.top());
        } else {            
            return (static_cast<double>(left_.top()) + right_.top()) / 2;
        }
    }
    double findMedian() {
        if (left_.size() > right_.size()) return (double)left_.top();
        else {
            return ((double)left_.top() + (double) right_.top())*0.5;   //typo right_.size()
        }
    }
    
private:
    //left_  right_     assceding order combined
    priority_queue<int> left_; //left max heap with max at top
    priority_queue<int,vector<int>, greater<int>> right_;  //right min heap with min at top
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
