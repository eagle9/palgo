// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
//shaun code from gy's 1 register idea, accepted after 1 bug fix, always think if the register is used or not
//runtime 45ms, faster than 96%, mem less than 100%
class PeekingIterator implements Iterator<Integer> {
    private boolean flag = false;
    private int copy;
    private Iterator<Integer> it;
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    it = iterator;
	}

    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        if (!flag) {
            copy = it.next();
            flag = true;  //registered used
            return copy;
        }
        //flag true, register used
        return copy;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    if (flag) {
            flag = false;
            return copy;
        }
        return it.next();
	}

	@Override
	public boolean hasNext() {
	    return flag || it.hasNext();
	}
}
