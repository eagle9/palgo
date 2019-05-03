//jz code, beats 30%
bool cmp(const int& a, const int& b) {
    return a > b;
}

class Solution {
private:
	priority_queue<int, vector<int>, greater<int>> queue;
	int k;

public:
    Solution(int k) {
        // initialize your data structure here.
        this->k = k;
    }

    void add(int num) {
        // Write your code here
        if (queue.size() < k) {
            queue.push(num);
        } else if (queue.top() < num) {
            queue.pop();
            queue.push(num);
        }
    }

    vector<int> topk() {
        // Write your code here
        vector<int> topk;
        int n = queue.size();
        for (int i = 0; i < k && i < n ; ++i) {
            topk.push_back(queue.top());
            queue.pop();
        }

        for (int i = 0; i < n; ++i)
            queue.push(topk[i]);
        sort(topk.begin(), topk.end(), cmp);
        return topk;
    }
};
