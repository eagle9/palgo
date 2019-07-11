//https://zhanghuimeng.github.io/post/leetcode-904-fruit-into-baskets/
//cutting:  understand the problem, <= 2 types fruits and sub array
//naturally use sliding window and 2p
//use a hash table to model the 2 baskets, fruit type to its count 
    //put a fruit into, hash[type]++
    //remove a fruit from baskets,  hash[type]--, if count ==0, erase
    //hash.size() <= 2 valid
//runtime 192ms, faster than 40%, mem less than 50%
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int left = 0;  // left edge of window
        unordered_map<int, int> cntMap; //use a map to store fruits, fruit type to its count 
        int res = -1; //to store max total of fruits, positive number, init with -1
        // 遍历窗口后沿
        for (int right = 0; right < tree.size(); right++) {
            //add fruit into baskets, type tree[right] count ++
            cntMap[tree[right]]++;
            // >2 types, contract left
            // remove fruit from left till type number <= 2
            while (cntMap.size() > 2) {
                cntMap[tree[left]]--;
                if (cntMap[tree[left]] == 0)
                    cntMap.erase(tree[left]);
                left++;
            }
            //<= 2 types, valid window, and update max window size
            res = max(res, right - left + 1);
        }
        return res;
    }
};
