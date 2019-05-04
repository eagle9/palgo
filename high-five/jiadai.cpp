/**
 * Definition for a Record
 */
#include <iostream>
#include <vector>
#include <map>
#include <queue> //priority_queue
#include <unordered_map>
using namespace std;
class Record {
public:
	int id, score;
	Record(int id, int score) {
		this->id = id;
		this->score = score;
	}
 };
class Solution {
public:
    /**
     * @param results a list of <student_id, score>
     * @return find the average of 5 highest scores for each person
     * map<int, double> (student_id, average_score)
     */
    map<int, double> highFive(vector<Record>& results) {
        // Write your code here
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> table;
        for (Record r : results) {
            auto& pq = table[r.id];
            if (pq.size() < 5) {
                pq.push(r.score);
            }
            else if (pq.top() < r.score) {
                pq.pop();
                pq.push(r.score);
            }
        }
        
        map<int, double> result;
        for (auto p : table) {
            double sum = 0;
            int count = 0;
            auto& pq = p.second;
            while (!pq.empty()) {
                ++count;
                sum += pq.top();
                pq.pop();
            }
            
            result[p.first] = sum / count;
        }
        
        return result;
    }
};
int main() {
	vector<vector<int>> scores = {{1,91},{1,92},{2,93},{2,99},{2,98},{2,97},{1,60},{1,58},{2,100},{1,61}};
	vector<Record> records(scores.size(),Record(0,0));
	int i = 0;
	for (auto& v: scores) {
		records[i++] = Record(v[0],v[1]);
	}
	map<int,double> res = Solution().highFive(records);	
	for (auto& p: res) {
		cout << p.first << ",average score=" << p.second << endl;
	}
}
