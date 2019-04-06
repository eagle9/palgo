	/*
	Runtime: 0 ms, faster than 100.00% of Java online submissions for Kth Smallest Element in a Sorted Matrix.
	Memory Usage: 43.9 MB, less than 1.01% of Java online submissions for Kth Smallest Element in a Sorted Matrix.
	grandyang binary search

	 */
	class Solution {
		public int kthSmallest(int[][] matrix, int k) {
			int n = matrix.length; //n x n matrix
			int left = matrix[0][0], right = matrix[n-1][n-1];
			while (left < right) {
				int mid = left + (right - left)/2;
				int cnt = searchLessEqual(matrix,mid);
				if (cnt < k) left = mid + 1;
				else right = mid;
			}
			return left;
		}
		//find number of elements that <= target, O(m+n)
		int searchLessEqual(int [][] matrix, int target) {
			int n = matrix.length; //n x n matrix
			//start from last row, first col
			int i = n - 1, j = 0, cnt = 0;
			while ( i >= 0 && j < n) {
				if (matrix[i][j] <= target) {
					cnt += i + 1;  // i numbers <= above the number
					++j;  //move to right, to find more
				}else { //matrix i,j > target, move up one row 
					--i;
				}
			}
			return cnt;
		}
	}
