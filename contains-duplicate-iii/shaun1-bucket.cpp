//lt 
//bucket and neighboring buckets
//runtime 16ms, faster than 93%, mem less than 5%
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) return false;
        int n = nums.size();
        unordered_map<long,long> window;
        long bucket_size = (long)t+1;
        for (int i = 0; i < n; ++i){
            long bucket = getBucket(nums[i],bucket_size);
            if (window.count(bucket)) return true;
            if ((window.count(bucket-1)) && abs(nums[i] - window[bucket - 1]) < bucket_size) return true;
            if (window.count(bucket+1) && abs(nums[i] - window[bucket + 1]) < bucket_size) return true;
            window[bucket] = nums[i];
            if (i >= k) {
                long oldest_bucket = getBucket(nums[i - k] ,bucket_size);
                window.erase(oldest_bucket);
            }
            
        }
        return false;
    }
private:
    //this will need some debugging
    //-3 / 5 = 0 and but we need -3 / 5 = -1
    long getBucket(long x, long w) {
        return x < 0 ? (x + 1) / w - 1 : x / w;
    }

};
