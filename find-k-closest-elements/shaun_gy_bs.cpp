//grandyang binary search, beats 99.61%
//try to locate the subarray directly
//shuan read and understood
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            //  arr[mid]     x     arr[mid+k]
            // dist1 >  dist2
            if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
            // dist1 <= dist2, 
            else right = mid;
        }
        //left  == right now, dist1 dist2 balanced
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

/*
用到了二分搜索法。其实博主最开始用的方法并不是帖子中的这两个方法，虽然也是用的二分搜索法，但博主搜的是第一个不小于x的数，然后同时向左右两个方向遍历，每次取和x距离最小的数加入结果res中，直到取满k个为止。但是下面这种方法更加巧妙一些，二分法的判定条件做了一些改变，就可以直接找到要返回的k的数字的子数组的起始位置，感觉非常的神奇。每次比较的是mid位置和x的距离跟mid+k跟x的距离，以这两者的大小关系来确定二分法折半的方向，最后找到最近距离子数组的起始位置
*/
