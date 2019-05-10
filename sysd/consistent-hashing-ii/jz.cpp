#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
using namespace std;
class Solution {
public:
    int n, k;
    map<int, int> shards; //map shard index to machine id
    set<int> ids; //set of shards id used, shard index is randomly generated
    // @param n a positive integer --- total number of shards along the ring
    // @param k a positive integer --- number of shards for a single machine
    // @return a Solution object
	
    /*static Solution create(int n, int k) {
        // Write your code here
        Solution solution = Solution();
        solution.n = n;
        solution.k = k;
		cout << "n=" << n << ",k=" << k << endl;	
        return solution;
    }*/

	Solution(int n, int k) {
		this->n = n;
		this->k = k;
	}

    // @param machine_id an integer
    // @return a list of shard ids that are hosted by the machine, number of shards = k
    vector<int> addMachine(int machine_id) {
        vector<int> random_nums;
		cout << "k=" << k << endl;
        for (int i = 0; i < k; ++i) {
            int index;
            do {
                index = rand() % n; //random shard id from 0 to n-1
            } while (ids.find(index) != ids.end());
			//insert a random shard index that is not yet used 
            random_nums.push_back(index);
            ids.insert(index);
            shards[index] = machine_id;
        }

        sort(random_nums.begin(), random_nums.end());
        return random_nums;
    }

    // @param hashcode an integer, or key part of the data
    // @return a machine id which has a shard >= hashcode and closest to hashcode
    int getMachineIdByHashCode(int hashcode) {
		//lowerbound, >= hashcode but minimized, sorted, it whose value is >=
		//hashcode as lower bound 
        map<int, int>::iterator it = shards.lower_bound(hashcode); //first it that >= hashcode
		
        if (it == shards.end()) //all before hashcode, hashcode can not be lowerbound, go to begin
            return shards.begin()->second;
        else
            return it->second; //it >= hashcode, first such 
    }
};
/* 
example test
create(100, 3)
addMachine(1)
>> [3, 41, 90]  => 三个随机数
getMachineIdByHashCode(4)
>> 1
addMachine(2)
>> [11, 55, 83]
getMachineIdByHashCode(61)
>> 2
getMachineIdByHashCode(91)
>> 1
*/
int main() {
	//Solution s(100,3); ---> wrong
	//Solution s = Solution::create(100,3);
	Solution s(100,3);
	vector<int> v = s.addMachine(1); 
	cout << "shards for machine 1:" << endl;
	for (int id: v) cout << id << endl;
	int h = 4;
	cout << "machine id for hashcode " << h << ":" << s.getMachineIdByHashCode(h) << endl;
	v = s.addMachine(2);
	cout << "shards for machine 2:" << endl;
	for (int i: v) cout << i << endl;
	cout << "all shards:" << endl;
	for (auto p: s.shards) cout << p.first <<"," << p.second << endl; 
	cout << "-------------" << endl;
	h = 61;
	cout << "machine id for hashcode " << h << ":" << s.getMachineIdByHashCode(h) << endl;
	h = 91;
	cout << "machine id for hashcode " << h << ":" << s.getMachineIdByHashCode(h) << endl;
}
