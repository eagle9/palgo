class MedianFinder {
    //grandyang two heaps, shaun in java, beats 49%
    
    /** initialize your data structure here. */
    public MedianFinder() {
        Comparator<Integer> revCmp = new Comparator<Integer>() {
            @Override
            public int compare(Integer left, Integer right) {
                //return right.compareTo(left);
                return right.intValue() - left.intValue();
            }
        };
        
        //maxHeap max at root
        maxHeap = new PriorityQueue<Integer>(revCmp);
        //minHeap min at root
        minHeap = new PriorityQueue<Integer>();
        //   maxHeap          smaller  \/
        //   num                       ----
        //   minHeap      larger       /\
        //
    }
    private PriorityQueue<Integer> maxHeap, minHeap;
    
    public void addNum(int num) {
        //smaller half goes to maxHeap
        //larger half goes to minHeap
        //minHeadp size 1+ or == maxHeap
        minHeap.add(num);
        int min = minHeap.poll(); //take the min
        maxHeap.add(min);
        //maxHeap.add(minHeap.peek());
        //minHeap.poll();
        //the following will make sure minHeap.size >= maxHeap.size
        if (minHeap.size() < maxHeap.size()) {
            int max = maxHeap.poll();
            minHeap.add(max);
            //minHeap.add(maxHeap.peek());
            //maxHeap.poll();
        }
    }

    public double findMedian() {
        int min = minHeap.peek();
        int max = maxHeap.peek();
        return minHeap.size() > maxHeap.size() ? min : 0.5 *(min + max);
    }
    
}


/*
//grandyang using two heaps, beats 93%
class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return small.size() > large.size() ? small.top() : 0.5 *(small.top() - large.top());
    }

private:
    priority_queue<long> small, large;
};
*/


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */


