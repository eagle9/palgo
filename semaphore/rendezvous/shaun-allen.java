//my solution, based on the previous hint:
Thread A
1 statement a1
2 aArrived.signal()
3 bArrived.wait()
4 statement a2
Thread B
1 statement b1
2 bArrived.signal()
3 aArrived.wait()
4 statement b2
/*
While working on the previous problem, you might have tried something like
this:
Thread A
1 statement a1
2 bArrived.wait()
3 aArrived.signal()
4 statement a2
Thread B
1 statement b1
2 bArrived.signal()
3 aArrived.wait()
4 statement b2
This solution also works, although it is probably less efficient, since it might
have to switch between A and B one time more than necessary.

Again, while working on the previous problem, you might have tried something
like this:
Thread A
1 statement a1
2 bArrived.wait()
3 aArrived.signal()
4 statement a2
Thread B
1 statement b1
2 aArrived.wait()
3 bArrived.signal()
4 statement b2
If so, I hope you rejected it quickly, because it has a serious problem. Assuming
that A arrives first, it will block at its wait. When B arrives, it will also
block, since A wasn’t able to signal aArrived. At this point, neither thread can
proceed, and never will.
This situation is called a deadlock and, obviously, it is not a successful
solution of the synchronization problem. In this case, the error is obvious, but
often the possibility of deadlock is more subtle.
*/
