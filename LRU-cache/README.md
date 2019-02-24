146. LRU Cache
Hard
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

Companies: Amazon | 67 Bloomberg | 27 Microsoft | 22 Facebook | 18 Google | 14 Uber | 14 Apple | 13 Zillow | 8 Two Sigma | 6 Oracle | 6 Adobe | 6 Twilio | 4 VMware | 4 Yahoo | 4 Salesforce | 4 Baidu | 3 eBay | 3 Cisco | 3 Snapchat | 3 Goldman Sachs | 3 Nvidia | 3 Lyft | 2 Pinterest | 2 GoDaddy | 2 SAP | 2 

Similar: 
LFU Cache Hard
Design In-Memory File System Hard
Design Compressed String Iterator Easy

Topic: Design

90% freq bar!!!! 
