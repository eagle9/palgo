//shaun recital of c++, how to use c++ priority_queue
//default is maxHeap,  for minHeap declare with 3 parameters
//pop does not return anything, use top and pop together
//runtime  180ms, faster than 90%
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>,greater<int>> minHeap;
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        while (minHeap.size() > maxHeap.size()) {
            int min1 = minHeap.top();
            maxHeap.push(min1);
            minHeap.pop();
        }
        //minHeap.size <= maxHeap.size
    }
    
    double findMedian() {
        if (minHeap.size() < maxHeap.size()) return (double)maxHeap.top();
        else {
            double a = maxHeap.top(), b = minHeap.top();
            return 0.5 * (a + b);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
