556. Standard Bloom Filter
Difficulty: Medium

http://www.lintcode.com/en/problem/standard-bloom-filter/

Implement a standard bloom filter. Support the following method:

StandardBloomFilter(k),The constructor and you need to create k hash functions.
add(string). add a string into bloom filter.
contains(string). Check a string whether exists in bloom filter.
Example

StandardBloomFilter(3)
add("lint")
add("code")
contains("lint") // return true
contains("world") // return false
