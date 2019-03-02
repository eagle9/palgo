//shaun's 2nd try, checked lt two heaps idea, added two lines, accepted
//runtime 124ms, faster than 98%
class MedianFinder1 {

    /** initialize your data structure here. */
    public MedianFinder1() {
        minHeap = new PriorityQueue<Integer> ();
        maxHeap = new PriorityQueue<Integer>(new Comparator<Integer>() {
			@Override
			public int compare(Integer a, Integer b) {
				return  b.intValue() - a.intValue();
			}
        	
        });
    }
    private PriorityQueue<Integer> minHeap = null;
    private PriorityQueue<Integer> maxHeap = null;
    public void addNum(int num) {
        maxHeap.offer(num);
        int max = maxHeap.poll(); //key 1
        minHeap.offer(max);  //key2, so close 
        while (minHeap.size() > maxHeap.size()) { //use while okay too
        	int temp = minHeap.poll();
        	maxHeap.offer(temp);
        }
        //minHeap.size <=  maxHeap.size
    }
    
    
    public double findMedian() {
        if (minHeap.size() < maxHeap.size()) return (double)maxHeap.peek();
        else  {
        	double a = (double)minHeap.peek(), b = (double)maxHeap.peek();
        	return 0.5*(a + b);
        }
    }
    
    //adding to which heap first does not matter
    public void addNum2(int num) {
        minHeap.offer(num);
        int min = minHeap.poll();
        maxHeap.offer(min);
        while (maxHeap.size() > minHeap.size()) {
        	int temp = maxHeap.poll();
        	minHeap.offer(temp);
        }
        //maxHeap.size <=  minHeap.size
    }
    
    public double findMedian2() {
        if (maxHeap.size() < minHeap.size()) return (double)minHeap.peek();
        else  {
        	double a = (double)minHeap.peek(), b = (double)maxHeap.peek();
        	return 0.5*(a + b);
        }
    }
}

//shaun's 1st try, wrong answer
class MedianFinder {
    /** initialize your data structure here. */
    public MedianFinder() {
        minHeap = new PriorityQueue<Integer> ();
        maxHeap = new PriorityQueue<Integer>(new Comparator<Integer>() {
			@Override
			public int compare(Integer a, Integer b) {
				return  b.intValue() - a.intValue();
			}
        	
        });
    }
    private PriorityQueue<Integer> minHeap = null;
    private PriorityQueue<Integer> maxHeap = null;
    public void addNum(int num) {
        maxHeap.offer(num);
        while (maxHeap.size() > minHeap.size()) { 
        	int temp = maxHeap.poll();
        	minHeap.offer(temp);
        }
        //maxHeap.size <=  minHeap.size
    }
    
    public double findMedian() {
        if (maxHeap.size() < minHeap.size()) return (double)minHeap.peek();
        else  {
        	double a = (double)minHeap.peek(), b = (double)maxHeap.peek();
        	return 0.5*(a + b);
        }
    }
    
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
