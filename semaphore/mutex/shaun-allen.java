/*
 * Create a semaphore named mutex that is initialized to 1. A value of one means
that a thread may proceed and access the shared variable; a value of zero means
that it has to wait for another thread to release the mutex.
*/
Thread A
mutex.wait()
	// critical section
	count = count + 1
mutex.signal()
Thread B
mutex.wait()
	//# critical section
	count = count + 1
mutex.signal()
/*
Since mutex is initially 1, whichever thread gets to the wait first will be able
to proceed immediately. Of course, the act of waiting on the semaphore has the
effect of decrementing it, so the second thread to arrive will have to wait until the first signals.

I have indented the update operation to show that it is contained within the
mutex.
*/
