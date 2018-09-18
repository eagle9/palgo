594. strStr II
Implement strStr function in O(n + m) time.

strStr return the first index of the target string in a source string. The length of the target string is m and the length of the source string is n.
If target does not exist in source, just return -1.

Example
Given source = abcdef, target = bcd, return 1.
Java String indexOf(), C++ strstr() use O(n*m) brute force comparison; Golang strings Index() use Rabin-Karp time complexity O(n+m). KMP is O(n+m), but hard to implement
