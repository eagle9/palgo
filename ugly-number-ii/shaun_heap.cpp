//signed integer overflow
class Solution0000 {
public:
    int nthUglyNumber(int n) {
        vector<int> factors = {2,3,5};
        
        unordered_set<int> set1;
        priority_queue<int,vector<int>, greater<int>> minHeap;
        int i = 0; 
        minHeap.push(1);
        set1.insert(1);
        while (true) {
            int t = minHeap.top(); minHeap.pop();
            i++; //ith ugly number
            if (i == n) return t;
            
            for (int f: factors) {
                long k = f*t;
                if (!set1.count(k)) {
                    minHeap.push(k);
                    set1.insert(k);
                }
            }
        }
    }
};

//shaun idea of using hashset and heap upon jz hint
//accepted after overcoming signed integer overflow, int --> long, return (int) res
//runtime 140ms, faster than 14%, mem less than 9%
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long> factors = {2,3,5};
        
        unordered_set<long> set1;
        priority_queue<long,vector<long>, greater<long>> minHeap;
        int i = 0; 
        minHeap.push(1);
        set1.insert(1);
        while (true) {
            long t = minHeap.top(); minHeap.pop();
            i++; //ith ugly number
            if (i == n) return (int)t;
            
            for (long f: factors) {
                long k = f*t;
                if (!set1.count(k)) {
                    minHeap.push(k);
                    set1.insert(k);
                }
            }
        }
    }
};
