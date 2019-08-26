//Listing 3.10: Reusable barrier solution
1 # rendezvous
2
3 mutex.wait()
4 count += 1
5 if count == n:
6 turnstile2.wait() # lock the second
7 turnstile.signal() # unlock the first
8 mutex.signal()
9
10 turnstile.wait() # first turnstile
11 turnstile.signal()
12
13 # critical point
14
15 mutex.wait()
16 count -= 1
17 if count == 0:
18 turnstile.wait() # lock the first
19 turnstile2.signal() # unlock the second
20 mutex.signal()
21
22 turnstile2.wait() # second turnstile
23 turnstile2.signal()
