#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <iostream>
using namespace std;

//http://bookshadow.com/weblog/2017/07/02/leetcode-design-log-storage-system/
//shaun own idea with ordered map, bookshadow convert key based on gra, prefix substring, similar to my idea, kind of my implementation

//use hashmap and range query iterator all keys
//use unordered_map, runtime 28ms, faster than 65%, mem less than 100%

//use map lower_bound, runtime ==== ??
class LogSystem {
private:
    unordered_map<string, int> dmap;
    //                             0 . 4     10
    //string gras[5] = {"Year","Month","Day","Hour","Minute"}; -- works
    vector<string> gras = split("Year:Month:Day:Hour:Minute", ':'); // -- works
    //end index  2001:mo:da:hh:mm:ss
    //           0   4  7 .10 13 16
    //int ends[5] = {4, 7, 10, 13, 16};  //--works
    vector<int> ends = {4,7,10,13,16}; //--works
    
    string getKeyByGra(string timestamp, string gra) {
        for (int i = 0; i < 5; i++) {
            if (gra == gras[i]) {
                return timestamp.substr(0, ends[i]);
            }
        }
        return timestamp;
    }
    
    vector<string> split(string text, char ch) {
        istringstream is(text);
        string token;
        vector<string> res;
        while(getline(is, token, ch )) {
            res.push_back(token);
        }
        return res;
    }
    /*
    string join(string ch, vector<string> input) {
        string res = "";
        for (int i = 0; i < input.size(); ++i) {
            res += (i ==0? input[i]: ch + input[i]);
        }
        return res;
    }
    //after gra, all set to 00
    string foo(string timestamp, string gra) {
        int j = 0;
        for (int i = 0; i < gras.size(); i++) {
            if (gras[i] == gra) {
                j = i;
                break;
            }
        }
        vector<string> t = split(timestamp,':');
        for (int i = 0; i < t.size(); i++) {
            if (i > j) t[i] = "00";
        }
        return join(":", t);
    }*/
public:    
    LogSystem() {
        //gras = split("Year:Month:Day:Hour:Minute", ':');
    }
    
    void put(int id, string timestamp) {
        dmap[timestamp] = id;
    }
    
    //how about: instead of iterate all keys, start from start key? 
    vector<int> retrieve(string s, string e, string gra) {
        //convert all keys with gra
        string sk = getKeyByGra(s, gra);
        string ek = getKeyByGra(e, gra);
        vector<int> ans;
        
        for (auto kv: dmap) {
        //for (String key: dmap.tailMap(foo(s,gra)).keySet()) {
        //string skfoo = foo(sk, gra);
        //auto it1 = dmap.lower_bound(skfoo);
        //for (auto it = it1; it != dmap.end(); ++it) {
            string ck = getKeyByGra(kv.first, gra);
            //sk <= ck .                ck <= endk
            if (sk <= ck && ck <= ek) {
                ans.push_back(kv.second);
            }
        }
        
        return ans;
    }

};

/*
int main() {
 	LogSystem log_sys;
	log_sys.put(1, "2017:01:01:23:59:59");
	log_sys.put(2, "2017:01:01:22:59:59");
	log_sys.put(3, "2016:01:01:00:00:00");
	vector<int> res = log_sys.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"); // return [1,2,3], because you need to return all logs within 2016 and 2017.
	for (auto id: res) {
		cout << id << endl;
	}
}
*/
