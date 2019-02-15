class Solution {
public:
    /**
     * @param n a positive integer
     * @return n x 3 matrix
     */
    vector<vector<int>> consistentHashing(int n) {
        // Write your code here
        vector<vector<int>> result;
        vector<int> machine = {0, 359, 1};
        result.push_back(machine);
        for (int i = 1; i < n; ++i) {
            int index = 0;
            for (int j = 1; j < i; ++j) {
                if (result[j][1] - result[j][0] > result[index][1] - result[index][0]) {
                    index = j;
                }
            }
           	int start = result[index][0], end = result[index][1]; 
			int mid = start + (end - start)/ 2;
            machine[0] = mid + 1;
            machine[1] = end;
            machine[2] = i + 1; //machine id

            result[index][1] = mid;
            result.push_back(machine);
        }
        
        return result;
    }
};
