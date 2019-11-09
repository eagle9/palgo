#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;
/*
class Column {
public:
		int key;
		string value;
		Column(int key, string value) {
			this->key = key;
			this->value = value;
		}

};
*/
struct Column { //class with all public members, use struct instead
	int key;
	string value;
};

//jiadai c++, shaun read and understood. Good use of map(treemap) lower_bound and upper_bound
class MiniCassandra {
public:
    MiniCassandra() {
        // initialize your data structure here.
    }
    
    /**
     * @param raw_key a string
     * @param column_start an integer
     * @param column_end an integer
     * @return void
     */
    void insert(string raw_key, int column_key, string column_value) {
        // Write your code here
        table[raw_key][column_key] = column_value;
    }

    /**
     * @param raw_key a string
     * @param column_start an integer
     * @param column_end an integer
     * @return a list of Columns
     */
    vector<Column> query(string raw_key, int column_start, int column_end) {
        // Write your code here
        vector<Column> result;
        auto it1 = table[raw_key].lower_bound(column_start); //first >= start
        auto it2 = table[raw_key].upper_bound(column_end); //first > end
        while (it1 != it2) { // from first >= start to end 
            result.push_back(Column(it1->first, it1->second));
            //++it1;
			//it1 = next(it1); //shaun update
			advance(it1,1); //shaun alternative to ++, works too
        }
        return result;
    }
    
private:
    unordered_map<string, map<int, string>> table;
};
int main() {
	/*
	* insert("google", 1, "haha")
	query("google", 0, 1)
	*/
	MiniCassandra db;
	db.insert("google",1, "haha1111");
	db.insert("google",2, "fofo2222");
	auto res = db.query("google", 0, 2);
	for (Column x: res) {
		cout << x.key << x.value << endl;
	}

}
