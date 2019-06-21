// Huahua binary index idea, 
//shaun read and understands
//transform number array to their sorted rank
// then look at rank: 1         2         ... n
//                    count1 count2          countn
// finding the count of smaller number boils down prefix sum of count1 ... countn array
// traverse array in reverse order, query and update binary index tree
// then reverse ans

// Runnning time: 40ms, faster than 66%, mem less than 42%

// Time complexity: O(nlogn)
// Space complexity: O(k), k is the number unique elements
//class FenwickTree {  
class BIT {
public:
    //FenwickTree(int n): sums_(n + 1, 0) {}
    BIT(int n): sums_(n+1,0) {}
    void update(int i, int delta) {
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i) const {        
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
private:
    static inline int lowbit(int x) { return x & (-x); }
    vector<int> sums_;
};
 
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // Sort the unique numbers, natural use of tree set
        set<int> sorted(nums.begin(), nums.end());
        
        // Map the number to its rank
        unordered_map<int, int> ranks;
        int rank = 0;
        for (const int num : sorted)
            ranks[num] = ++rank;
        
        vector<int> ans;
        //FenwickTree tree(ranks.size());
        //binary index tree to store what? 
        //the goal is to find count of numbers that smaller than current element
        BIT tree(ranks.size());
        
        // Scan the numbers in reversed order
        for (int i = nums.size() - 1; i >= 0; --i) {
            // Chechk how many numbers are smaller than the current number.
            int rank = ranks[nums[i]];
            //how many numbers that are smaller? 
            //rank 1    2 ....  rank
            // .   n1 . n2 .    n_rank
            //ans is prefix sum index rank-1, smaller before
            ans.push_back(tree.query(rank - 1));
            // Increse the count of the rank of current number.
            tree.update(rank, 1);
        }
        
        //std::reverse(ans.begin(), ans.end());
        //reverse ans to make it smaller after
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
