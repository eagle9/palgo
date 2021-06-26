/*
To allow multiple threads to run in the critical section, just initialize the
semaphore to n, which is the maximum number of threads that should be allowed.

At any time, the value of the semaphore represents the number of additional
threads that may enter. If the value is zero, then the next thread will block
until one of the threads inside exits and signals. When all threads have exited
the value of the semaphore is restored to n.

Since the solution is symmetric, it’s conventional to show only one copy of the
code, but you should imagine multiple copies of the code running concurrently
in multiple threads.
Listing 3.1: Multiplex solution
*/
multiplex = new Semaphore(n);
multiplex.wait(); //acquire
	//critical section
multiplex.signal(); //release
