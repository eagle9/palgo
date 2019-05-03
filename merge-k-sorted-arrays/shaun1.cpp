//shaun original idea and code, accepted after debugging failed test cases input [[][]]
//beats 7%
struct entry {
    int number; 
    int rowIndex; //row index
    int colIndex;
    entry(int n, int ri, int ci): number(n), rowIndex(ri), colIndex(ci) {};
    bool operator <(entry other) const {
        return number > other.number; //greater number in front
    }
};
class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        // write your code here
        priority_queue<entry> minHeap; //min number at the top
        int size = 0;
        for (int rowIndex = 0; rowIndex < arrays.size(); ++rowIndex) {
            if (!arrays[rowIndex].empty()) { //added after debugging 
                minHeap.push(entry(arrays[rowIndex][0],rowIndex, 0));
                size += arrays[rowIndex].size();
            }
        }
        vector<int> res(size);
        int i = 0;
        while (!minHeap.empty()) {
            entry t = minHeap.top(); minHeap.pop();
            //res.push_back(t.number);
            res[i++] = t.number;
            vector<int> row = arrays[t.rowIndex];
            if (t.colIndex+1 < row.size()) minHeap.push(entry(row[t.colIndex+1], t.rowIndex, t.colIndex+1));
        }
        return res;
    }
};
