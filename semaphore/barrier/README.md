3.5 Barrier
Consider again the Rendezvous problem from Section 3.2. A limitation of the
solution we presented is that it does not work with more than two threads.

Puzzle: Generalize the rendezvous solution. Every thread should run the
following code:
Listing 3.2: Barrier code
1 rendezvous
2 critical point

The synchronization requirement is that no thread executes critical point
until after all threads have executed rendezvous.

You can assume that there are n threads and that this value is stored in a
variable, n, that is accessible from all threads.

When the first n − 1 threads arrive they should block until the nth thread
arrives, at which point all the threads may proceed.
