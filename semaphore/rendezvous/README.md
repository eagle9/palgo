Rendezvous
Puzzle: Generalize the signal pattern so that it works both ways. Thread A has
to wait for Thread B and vice versa. In other words, given this code
Thread A
1 statement a1
2 statement a2
Thread B
1 statement b1
2 statement b2
we want to guarantee that a1 happens before b2 and b1 happens before a2. In
writing your solution, be sure to specify the names and initial values of your
semaphores (little hint there).
Your solution should not enforce too many constraints. For example, we
don’t care about the order of a1 and b1. In your solution, either order should
be possible.
This synchronization problem has a name; it’s a rendezvous. The idea is
that two threads rendezvous at a point of execution, and neither is allowed to
proceed until both have arrived.
