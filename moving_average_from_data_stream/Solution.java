//ling huchong, use Queue
//Your submission beats 97.00% Submissions!
public class MovingAverage {

    private Queue<Integer> que;
    private double sum = 0;
    private int size;

    /** Initialize your data structure here. */
    public MovingAverage(int size) {
        que = new LinkedList<Integer>();
        this.size = size;
    }
    
    public double next(int val) {
        // Write your code here
        sum += val;
        if (que.size() == size) {
            sum = sum - que.poll();
        }
        que.offer(val);
        return sum / que.size();
    }
}
