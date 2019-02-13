/*
Runtime: 19 ms, faster than 50.98% of Java online submissions for Kth Smallest Element in a Sorted Matrix.
Memory Usage: 44.6 MB, less than 1.01% of Java online submissions for Kth Smallest Element in a Sorted Matrix.
shaun java code with max heap idea.
*/
class Solution {
    	public int kthSmallest(int[][] matrix, int k) {
	    	//assume k= < m*n
	        int m = matrix.length, n = matrix[0].length;
	        //use a max heap where the max is at the top, all (except top) elements < top
	        PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer> () {
				@Override
				public int compare(Integer a, Integer b) {
					return b.intValue() - a.intValue() ;
				}
	        	
	        });
	        for (int i = 0; i < m; ++i) {
	        	for (int j = 0; j < n; ++j) {
                    pq.offer(matrix[i][j]);
	        		if (pq.size() > k) pq.poll(); // pq size will be k
	        	}
	        }
	        return pq.peek();
	    }
}
