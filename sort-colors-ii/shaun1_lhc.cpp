
class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        //if (colors.empty()) return;
        helper(colors, 1, k, 0, colors.size()-1);
        
    }
    //linhuchong, not template, why????, beats 11%
    void helper(vector<int>& colors, int from, int to, int left, int right) {
        if (from >= to) return; // only 1 color
        if (left >= right) return; //single or empty
        int mid = (from + to)/2;
        
        int i = left, j = right;
        while (i <= j) {
            while (colors[i] <= mid && i <= j) i++;
            while (colors[j] > mid && i <= j) j--;
            if (i < j) swap(colors[i++], colors[j--]);
        }
        //left j i right
        //int p = (colors[i] < mid)? i+1: i;
        // left p-1 < mid    p .. right  >= mid
        helper(colors, from, mid, left, j);
        helper(colors, mid+1,  to,   i, right);
        
    }
    
    //shaun's own helper, runtime error?????!!!!!
    void helper2(vector<int>& colors, int from, int to, int left, int right) {
        if (from >= to) return; // only 1 color
        if (left >= right) return; //single or empty
        int mid = (from + to)/2;
        
        int i = left, j = right;
        while (i < j) {
            while (colors[i] < mid && i < j) i++;
            while (colors[j] >= mid && i < j) j--;
            if (i < j) swap(colors[i++], colors[j--]);
        }
        //i == j
        int p = (colors[i] < mid)? i+1: i;
        // left p-1 < mid    p .. right  >= mid
        helper(colors, from, mid-1, left, p-1);
        helper(colors, mid,  to,     p, right);
        
    }
};
