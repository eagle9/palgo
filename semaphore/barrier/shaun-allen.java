n = the number of threads
count = 0 //count keeps track of how many threads have arrived. 
//mutex provides exclusive access to count so that threads can increment it safely.
//barrier is locked (zero or negative) until all threads arrive; then it should be unlocked (1 or more).
mutex = Semaphore(1)
barrier = Semaphore(0)

rendezvous
mutex.wait()
	count = count + 1
mutex.signal()

if count == n: barrier.signal()
barrier.wait()
barrier.signal()
critical point
