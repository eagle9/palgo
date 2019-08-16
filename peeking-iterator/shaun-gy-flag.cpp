// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
//grandyang idea using a flag and value copy
//shaun read and understand
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
        _flag = false;
    }

    int peek() {
        if (!_flag) _value = Iterator::next();
        _flag = true;
        return _value;
    }

    int next() {
        if (!_flag) return Iterator::next();
        _flag = false;
        return _value;
    }

    bool hasNext() const {
        return _flag || Iterator::hasNext();
    }

private:
    int _value;
    bool _flag;
};
