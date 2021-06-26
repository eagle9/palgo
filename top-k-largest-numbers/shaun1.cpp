//shaun original idea and code, first sub accepted, 
//beats 52%
//the key is to understand and master c++ priority_queue api and its usage
class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        // write your code here
        priority_queue<int, vector<int>, greater<int>> heap; //want min at top of the heap
        for (int x: nums) {
            heap.push(x);
            if (heap.size() > k) heap.pop(); //min element popped
            //top k largest number will be kept in the heap
        }
        vector<int> res(k);
        int i = k-1; 
        while (!heap.empty()){
            res[i--] = heap.top();
            heap.pop();
        }
        return res;
    }
};
