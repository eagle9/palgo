Multiplex
Puzzle: Generalize the previous solution so that it allows multiple threads to
run in the critical section at the same time, but it enforces an upper limit on
the number of concurrent threads. In other words, no more than n threads can
run in the critical section at the same time.
This pattern is called a multiplex. In real life, the multiplex problem occurs
at busy nightclubs where there is a maximum number of people allowed in the
building at a time, either to maintain fire safety or to create the illusion of
exclusivity.
