//idea：https://blog.csdn.net/chen_xinjia/article/details/69258706 
//runtime 26ms, faster han 93%
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int MIN_VALUE = Integer.MIN_VALUE;

        int MAX_VALUE = Integer.MAX_VALUE;

        int N1 = nums1.length;
        int N2 = nums2.length;
        if (N1 > N2) {// ensure first array is smaller array
            return findMedianSortedArrays(nums2, nums1);
        }

        if (N1 == 0)
            return ((double) nums2[(N2 - 1) / 2] + (double) nums2[N2 / 2]) / 2;
        int size = N1 + N2;
        int cutL = 0, cutR = N1;
        int cut1 = 0;  //N1 / 2;
        int cut2 = 0; //size / 2 - cut1;

        //
        //while (cut1 <= N1) {
        while (true) {
            cut1 = (cutR - cutL) / 2 + cutL;
            cut2 = size / 2 - cut1;
            if (cut1 < 0 || cut1 > N1) break;
            //边界条件，就是cut的位置可能在边缘，就是cut1=0或者cut1=N1，cut2=0或者cut2=N2的这些情况，我们将min和max两个特殊值分别加在数组1和数组2的两端，就可以统一考虑了
            double L1 = (cut1 == 0) ? MIN_VALUE : nums1[cut1 - 1];
            double L2 = (cut2 == 0) ? MIN_VALUE : nums2[cut2 - 1];
            double R1 = (cut1 == N1) ? MAX_VALUE : nums1[cut1];
            double R2 = (cut2 == N2) ? MAX_VALUE : nums2[cut2];
            if (L1 > R2)
                cutR = cut1 - 1;
            else if (L2 > R1)
                cutL = cut1 + 1;
            else {// Otherwise, that's the right cut.
                if (size % 2 == 0) {// total number is even
                    L1 = (L1 > L2 ? L1 : L2);  //greater of L1 and L2
                    R1 = (R1 < R2 ? R1 : R2);  //lesser of R1 and R2
                    return (L1 + R1) / 2; 
                }

                else { //size is odd, right side one more number
                    R1 = (R1 < R2 ? R1 : R2);       
                    return R1; 
                }
            }
        }
        return -1;
    }
}
