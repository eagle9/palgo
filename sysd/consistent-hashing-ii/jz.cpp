class Solution {
public:
    int n, k;
    map<int, int> shards;
    set<int> ids;
    // @param n a positive integer
    // @param k a positive integer
    // @return a Solution object
    static Solution create(int n, int k) {
        // Write your code here
        Solution solution = Solution();
        solution.n = n;
        solution.k = k;
        return solution;
    }

    // @param machine_id an integer
    // @return a list of shard ids
    vector<int> addMachine(int machine_id) {
        // Write your code here
        vector<int> random_nums;
        for (int i = 0; i < k; ++i) {
            int index;
            do {
                index = rand() % n;
            } while (ids.find(index) != ids.end());
            ids.insert(index);
            random_nums.push_back(index);
            shards[index] = machine_id;
        }

        sort(random_nums.begin(), random_nums.end());
        return random_nums;
    }

    // @param hashcode an integer
    // @return a machine id which has a shard >= hashcode and closest to hashcode
    int getMachineIdByHashCode(int hashcode) {
		//lowerbound, >= but minimized, sorted, it whose value is >=
		//hashcode as lower bound 
        map<int, int>::iterator it = shards.lower_bound(hashcode);
		
        if (it == shards.end()) //all before hashcode, hashcode can not be lowerbound
            return shards.begin()->second;
        else
            return it->second; //it >= hashcode, first such 
    }
};
