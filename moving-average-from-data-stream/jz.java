//ling huchong, use Queue
//Your submission beats 97.00% Submissions! at lintcode
//beats 50% at leetcode
public class MovingAverage {

    private Queue<Integer> que;
    private double sum = 0;
    private int size;  //moving window size

    /** Initialize your data structure here. */
    public MovingAverage(int size) {
        que = new LinkedList<Integer>();
        this.size = size;
    }
    
    public double next(int val) {
        // Write your code here
        sum += val;
        //if the queue size reach the window size, remove the head, update the sum, add the new number
        if (que.size() == size) {
            sum = sum - que.poll();
        }
        //add the new number
        que.offer(val);
        //return the average of the moving window
        return sum / que.size();
    }
}


/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
