//shaun original idea and code, accepted first sub after fixing typo
//beats only 1.2%
//also learned c++ contructor member variables initialization
class Solution {
public:
    /*
    * @param k: An integer
    */
    /*Solution(int k): k(k) {
        // do intialization if necessary
    }*/
    
    Solution(int k){
        this->k = k;
    }

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        // write your code here
        minHeap.push(num);
        while (minHeap.size() >k) minHeap.pop();
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        // write your code here
        vector<int> res;
        
        while (!minHeap.empty()){
            res.insert(res.begin(), minHeap.top());
            minHeap.pop();
        }
        for (int x: res) minHeap.push(x);
        return res;
    }
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};
