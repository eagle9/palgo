#include<bitset>
#include <vector>
#include <iostream>
using namespace std;
//jiadai, similar to jz
class HashFunction {
private:
    int cap, seed;
public:
    HashFunction(int cap, int seed) {
        this->cap = cap;
        this->seed = seed;
    }

    int hash(string& value) {
        int ret = 0;
        int n = value.size();
        for (int i = 0; i < n; ++i) {
            ret += seed * ret + value[i];
            ret %= cap;
        }
        return ret;
    }
};

class StandardBloomFilter {
public:
    StandardBloomFilter(int k) {
        this->k = k;
        for (int i = 0; i < k; ++i) {
            hashFunc.push_back(new HashFunction(100000 + i, 2 * i + 3));
        }
    }

    void add(string& word) {
        for (int i = 0; i < k; ++i) {
            int position = hashFunc[i]->hash(word);
            bits.set(position);
        }
    }

    bool contains(string& word) {
        for (int i = 0; i < k; ++i) {
            int position = hashFunc[i]->hash(word);
            if (!bits[position]) {
                return false;
            }
        }
        return true;
    }
    
private:
    int k;
    vector<HashFunction*> hashFunc;
    bitset<200000> bits;
};
int main() {

	StandardBloomFilter bf(3);
	//bf.add("lint");
	//bf.add("code")
	string word1 = "lint";bf.add(word1);
	string word2 = "code";bf.add(word2);
	string word3 = "world";
	cout << bf.contains(word1) << "<---true"<<endl; // return true
	cout << bf.contains(word3) << "<---false"<<endl;// return false
}
