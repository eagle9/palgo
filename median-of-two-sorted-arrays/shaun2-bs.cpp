//https://blog.csdn.net/chen_xinjia/article/details/69258706 
//idea from xinjia chen, binary search, cutting angle, O(log(min(m,n))) means binary search
//shaun read and understand
//runtime 16ms, faster than 98%, mem less than 72%
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 > N2) {// 确保N1是短的部分。
            return findMedianSortedArrays(nums2, nums1);
        }

        if (N1 == 0)
            return ((double) nums2[(N2 - 1) / 2] + (double) nums2[N2 / 2]) / 2;
        int size = N1 + N2;
        int left = 0, right = N1-1;
        int cut1 = N1 / 2;
        int cut2 = size / 2 - cut1;

        while (cut1 <= N1) {
            cut1 = (right - left) / 2 + left;
            cut2 = size / 2 - cut1;

            double L1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            double L2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            double R1 = (cut1 == N1) ? INT_MAX : nums1[cut1];
            double R2 = (cut2 == N2) ? INT_MAX : nums2[cut2];
            if (L1 > R2) right = cut1-1; //upper layer left side too large
            else if (L2 > R1) left = cut1+1; //lower layer left side too large
            else {// Otherwise, that's the right cut.
                if (size % 2 == 0) {// 偶数个数的时候
                    return (max(L1,L2) + min(R1,R2)) / 2; 
                }else {
                    return min(R1,R2); 
                }
            }
        }
        return -1;

    }
};

