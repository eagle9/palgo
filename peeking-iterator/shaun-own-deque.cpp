// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

//shaun's own idea using vector, then deque
//cutting: first used vector, where pop_front is not implemented,  then switch to deque, accepted after 1 bug fix (vector no pop_front)
//runtime 4ms, faster than 83%, mem less than 100%
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    for (int i: nums) data.push_back(i);
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return data.front();
        
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int res = data.front();
        data.pop_front();
        return res;
	}

	bool hasNext() const {
	    return !data.empty();
	}
private:
    deque<int> data;
};
