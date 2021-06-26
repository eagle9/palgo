//runtime 26ms, faster than 92%
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        //make sure the first array is the smaller array
        if (nums2.length < nums1.length)
            return findMedianSortedArrays(nums2, nums1);
        
        /*if (nums1.length == 0){
            if (nums2.length % 2 == 0) return (nums2[nums2.length/2-1] + nums2[nums2.length/2])/2.0;
            else return nums2[nums2.length/2];
        }*/ 
            
        int len = nums1.length + nums2.length;
        int lenHalf = len/2;
        
        int cut1 = 0, cut2 = 0;
        int cutL = 0, cutR = nums1.length;
        while (true) {
            if (cut1 > nums1.length || cut1 < 0) break;
            cut1 = cutL + (cutR-cutL)/2;
            cut2 = lenHalf - cut1;
            
            int L1 = (cut1 == 0)? Integer.MIN_VALUE: nums1[cut1-1];
            int R1 = (cut1 == nums1.length)? Integer.MAX_VALUE: nums1[cut1];
            int L2 = (cut2 == 0)? Integer.MIN_VALUE: nums2[cut2-1];
            int R2 = (cut2 == nums2.length)? Integer.MAX_VALUE: nums2[cut2];
            
            if (L1 > R2) {
                cutR = cut1 - 1;
            }
            if (L2 > R1) {
                cutL = cut1 + 1;
            }
            if (L1 <= R2 && L2 <= R1) { //right cut
                if (len % 2 == 0) {
                    return (Math.max(L1,L2) + Math.min(R1,R2))/2.0;
                }else 
                    return Math.min(R1,R2);
            }
        }
        return -1;
    }
}
