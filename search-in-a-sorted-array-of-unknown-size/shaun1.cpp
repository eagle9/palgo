// Forward declaration of ArrayReader class.
class ArrayReader;

//shaun's own idea, runtime 52ms, faster than 77%, less than 29% memory
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        
        if (reader.get(0) ==  target) return 0;
        int i = 1;
        while (reader.get(i) < target) i *= 2;
        // reader.get(i) >= target
        int left = 1, right = i;
        while (left <= right) {
            int mid = left + (right - left)/2;
            int val = reader.get(mid);
            if (val == target) return mid;
            else if (val < target)  left = mid+1;
            else  right = mid - 1; // target < val
        }
        //exit right left, no need to check out of bound now
        if (reader.get(left) == target) return left;
        return -1;
    }
};
