//runtime 68ms, faster than 59% 
////idea https://www.cnblogs.com/lightwindy/p/9795918.html
//https://buptwc.com/2018/06/26/Leetcode-857-Minimum-Cost-to-Hire-K-Workers/
//shaun rewrote with maxheap, max at the top of the heap, heap stores the smaller elements
class Solution {
    public double mincostToHireWorkers(int[] q, int[] w, int K) {
       
       
        //create workers array of pair (w/q,q)
        double [][] workers = new double[q.length][2];
        for (int i = 0; i < q.length; i++) 
            workers[i] = new double [] { (double)w[i]/q[i], (double)q[i]};
        
        //sort (r,q) by r ascending
        Arrays.sort(workers, (a, b) -> Double.compare(a[0], b[0]));
        
       double res = Double.MAX_VALUE, qsum = 0;
        //create a pq/heap with max at the top
       PriorityQueue<Double> pq = new PriorityQueue<>( (a,b) -> Double.compare(b,a)); 
        /*
       PriorityQueue<Double> pq = new PriorityQueue<>(new Comparator<Double>(){
           public int compare(Double a, Double b) {
               return Double.compare(b,a);
           }
       });*/
        //the ratio worker[0] is the max w/q, we want the quality sum to be min with K workers
        //qsum store the sum of quality in the heap
       for (double[] worker: workers) {
           //ogether += and offer
           qsum += worker[1];
           pq.offer(worker[1]);
           
           if (pq.size() > K) qsum -= pq.poll(); //remove the larger quality in negative form and update qsum together
           
           //heap has K workers' quality, use current worker's w/q ratio
           if (pq.size() == K) res = Math.min(res, qsum * worker[0]);
       }
       return res;
    }
}
