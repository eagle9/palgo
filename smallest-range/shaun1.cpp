//shaun's own idea and accepted after debugging
//1)  record needs to have 3 fields
//2)  operator< parameter no reference, otherwise compile error
//3) curMax as b, not the new element
//runtime 52ms, faster than 97%, mem less than 76%
//to debug, it is key to run a simple example and be clear with details
struct record {
    int number;
    int i;
    int j;
    record(int n, int i, int j): number(n),i(i),j(j) {};
    //bool operator<(record& other) const{  //compile error
    bool operator<(record other) const{
        return number > other.number; //greater in front
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size(); //k lists
        vector<int> range; //init empty
        priority_queue<record> pq; //min number at top
        //push first element of each list into pq
        int curMax = INT_MIN;
        for (int i = 0; i < k; ++i) {
            record r = {nums[i][0],i,0};
            pq.push(r);
            curMax = max(curMax, nums[i][0]);
        }
        update(pq.top().number, curMax, range);
        
        //remove min from pq, choose a min from 
        while (true) {
            record t = pq.top(); pq.pop();
            t.j++;
            if (t.j < nums[t.i].size()) {
                curMax = max(curMax, nums[t.i][t.j]);
                pq.push({nums[t.i][t.j], t.i, t.j});
                update(pq.top().number, curMax, range);
            }else {
                break;
            }
            
        }
        return range;
    }
               
private:
        void update (int a, int b, vector<int>& range) {
            if (range.empty()) {
                range = {a,b};
            }else {
                if (b - a < range[1] - range[0]) {
                    range[1] = b;
                    range[0] = a;
                }else if (b-a == range[1] - range[0] && a < range[0]) {
                    range[1] = b;
                    range[0] = a;
                }
            }
        }
};
