#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;
int main() {
		string infile1 = "/Users/shaun/Downloads/stats.csv";
		ifstream infile(infile1);
		string line;
		map<int,int> m;
		while (getline(infile, line)) {
			istringstream iss(line);
			int reads;
			if (!(iss >> reads)) { break; } // error
			cout << reads << " <-reads" << endl;
			int bucket = reads/100;
			m[bucket]++;
		}
		for (auto kv: m) { 
			cout << kv.first << "," << kv.second << endl;
		}
}
