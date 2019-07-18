//TLE
//shaun own after laboring throughing mis-understanding of the problem requirements
//first sub TLE, misunderstandings of the problem
//second sub runtime error or wrong answer
//checked with grandyang, inside add, push val on matter what, why????
//finally accepted, runtime 48ms, faster than 85%, mem less than 17%
//my idea and code was close to be accepted, but lack a little bit, don't even understand why my code comparing val and top inside add function leads wrong answer!!!

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        //minHeap(nums.begin(), nums.end()); //not working
        
        for (const int x: nums){
            minHeap.push(x);
            while (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        this->k = k;
        //now top k in minHeap
    }
    
    int add(int val) {
        /*
        if (minHeap.empty() || val > minHeap.top()) { //bug 
            minHeap.push(val);
            while (minHeap.size() > k) {
                minHeap.pop();
            }
            
        }*/
        //if (minHeap.empty() || val >= minHeap.top()) minHeap.push(val); //wrong answer
        minHeap.push(val);
        while (minHeap.size() > k) {
            minHeap.pop();
        }
            
        
        return minHeap.top();
    }
private:
    int k;
    priority_queue<int,vector<int>, greater<int>> minHeap;
};

//grandyang, runtime 52ms, faster than 66%, mem less than 32%
class KthLargest2 {
public:
    KthLargest2(int k, vector<int> nums) {
        for (int num : nums) {
            q.push(num);
            if (q.size() > k) q.pop();
        }
        K = k;
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > K) q.pop();
        return q.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> q;
    int K;
};
/*
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        //minHeap(nums.begin(), nums.end()); //not working
        for (int i: nums) maxHeap.push(i);
        this->k = k;
    }
    
    int add(int val) {
        maxHeap.push(val);
        vector<int> temp;
        for (int i = 0; i < k-1; ++i) {
            temp.push_back(maxHeap.top());
            maxHeap.pop();
        }
        int res = maxHeap.top();
        //push popped numbers back into minHeap, so simulate the stream
        for (int i: temp) maxHeap.push(i);
        return res;
    }
private:
    priority_queue<int, vector<int>, greater<int>> minHeap; //min at the top
    int k;
    priority_queue<int> temp; //temp storage maxHeap, max at the top
};
*/
/*
testing: 
add3, minHeap: [8 5 4 3 2 ], 3rd largest is 4

add5, [8 5 5 4 3 2], 3rd larget is 5

add 10, minHeap:[10 8 5 5 4 3 2], return 5

add 9: minHeap: [10 9 8 5 5 4 3 2],return 8
add 4: minHeap: [10 9 8 5 5 4 4 3 2], return 8



*/
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
