//shaun's 2nd try, checked lt two heaps idea, added two lines, accepted
//runtime 124ms, faster than 98%
//cutting chain maxHeap minHeap from left to right
// left size is 1+ or equal to right size
/*
Runtime: 72 ms, faster than 18.53% of Java online submissions for Find Median from Data Stream.
Memory Usage: 61.7 MB, less than 91.53% of Java online submissions for Find Median from Data Stream.

*/
class MedianFinder {

    /** initialize your data structure here. */
    public MedianFinder() {
        
        //. left.   ------- right
        //maxHeap --- ... --- minHeap
        maxHeap = new PriorityQueue<Integer>( (a,b) -> b.intValue() - a.intValue());
        minHeap = new PriorityQueue<Integer> ();
        
    }
    private PriorityQueue<Integer> maxHeap = null, minHeap = null;
    
    public void addNum(int num) {
        if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
            maxHeap.offer(num);

        }else { 
            minHeap.offer(num);
        }

        //left_.size = or +1 right.size
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.offer(minHeap.poll());
            
        } // second try add else, does not matter, later removed
        if (maxHeap.size() == minHeap.size() + 2) {
            minHeap.offer(maxHeap.poll());
        }
        //end up with left.size = right.size or one more
    }
    
    
    public double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return (double) maxHeap.peek();
        } else {
            return (double) (maxHeap.peek() + minHeap.peek()) / 2.0;
        }

    }
    
    
    
    
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

