//runtime 68ms, faster than 59% 
////idea https://www.cnblogs.com/lightwindy/p/9795918.html
//https://buptwc.com/2018/06/26/Leetcode-857-Minimum-Cost-to-Hire-K-Workers/
/*
 * 这道题有点意思，要雇佣K个人，使得所花钱最少，雇佣需满足两个条件，一是最后给的钱必须成比例，二是不能低于最小值
我们不妨设最后雇佣时给第i个人的钱为p[i]，则对于被选上的K个人来说，都有相同的比例 p[i] / quality[i]（根据条件1）
也就是说一旦我们选定了比例 r，那么最后选的K个人一定都满足 r * quality[i] > wage[i]（因为已经被选上了自然满足条件2）
上式逆推为 r > (wage/quality),故我们将所有人按照 wage/quality 的大小排序，依次作为r 来判断最后的总价格。
注意N,K都达到了10000，O(n^2)的方法显然不行（绝大部分情况下）
 *
 *
 * */

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
