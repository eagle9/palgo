/*
 * comparison in c++
 * method 1:
 * define Compare struct(class with public okay) with bool operator()
 * then you can use the Compare class inside type declaration, such as
 * set<Type, TypeCompare>, priority_queue<Type,vector<Type>,TypeCompare>,
 * map<Type,TypeCompare>
 * TypeCompre TypeCmp;
 * or in sort(vec.begin(), vec.end(),TypeCmp) 
 *
 *
 *
 */
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

using std::priority_queue;
using std::vector;
using std::cout;
using std::endl;
using std::set;

class Toast {
public:
	int bread;
	int butter;

	Toast(int bread, int butter)
		: bread(bread), butter(butter) {}
};
//same comparison, priority queue pop elements desconding order, set.begin to end ascending order
class ToastCompare {
public:
	bool operator()(const Toast &t1, const Toast &t2) const {
		int t1value = t1.bread * 1000 + t1.butter;
		int t2value = t2.bread * 1000 + t2.butter;
		return t1value < t2value;
	}
};
struct kv {
    int key;
    std::string value;
    kv(int k, const std::string& s) : key(k), value(s) {};
	//bool operator<(kv& other) const { //kv& other -->not working, compiler error
	bool operator<(kv other) const { //kv& other
		return key < other.key; // if true, key is ahead of other.key
	}
};

struct kvCompare {
    //inline bool operator() (const kv& struct1, const kv& struct2) {  //----> working
    inline bool operator() (kv struct1, kv struct2) const { //---> working too
        return (struct1.key < struct2.key);
    }
};


int main(int argc, char ** argv) {
	Toast toast1(2, 200);
	Toast toast2(1, 30);
	Toast toast3(1, 10);
	Toast toast4(3, 1);
	
	//priority_queue<Toast> queue;
	priority_queue<Toast, vector<Toast>, ToastCompare> queue;

	queue.push(toast1);
	queue.push(toast2);
	queue.push(toast3);
	queue.push(toast4);

	while (!queue.empty()) {
		Toast t = queue.top();
		cout << "bread " << t.bread << " butter " << t.butter << std::endl;
		queue.pop();
	}
	//ToastCompare smaller is in front
    set<Toast,ToastCompare> set1;
    set1.insert(toast1);
  	set1.insert(toast2);
  	set1.insert(toast3);
  	set1.insert(toast4);
  	cout << "order in balanced tree set:" << endl;
  	while (!set1.empty()) {
    	auto it = set1.begin();
    	cout << "bread " << it->bread << " butter " << it->butter << std::endl;
    	set1.erase(it);
  	}

	vector <kv > vec;

	vec.push_back(kv(4, "test"));
	vec.push_back(kv(3, "a"));
	vec.push_back(kv(2, "is"));
	vec.push_back(kv(1, "this"));
	//comp cmp;
	//sort(vec.begin(), vec.end(), cmp);
	sort(vec.begin(), vec.end()); //sort 
	cout << "sorted vec<kv> with kv's own <operator:" << endl;
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i].key << "," << vec[i].value << endl;
	}
	//kvCompare kvCmp;
	sort(vec.begin(), vec.end(), kvCompare());
	cout << "sorted vec<kv> with kvCompare:" << endl;
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i].key << "," << vec[i].value << endl;
	}

	priority_queue<kv> pq;
	pq.push(kv(4, "test"));
	pq.push(kv(3, "a"));
	pq.push(kv(2, "is"));
	pq.push(kv(1, "this"));
	cout << "pq pop order:" << endl;
	while (!pq.empty()) {
		//If default comparison function is used, the returned element is also the greatest among the elements in the queue.
		auto e = pq.top(); pq.pop();
		cout << e.key << "," << e.value << endl;
	}
	return 0;
}

