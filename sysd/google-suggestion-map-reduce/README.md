1787. Google Suggestion(Map Reduce)
Use MapReduce framework to build a key-value index for Google Suggestion where the key is the prefix of a query and the value is the top 10 searched queries.

You don't need go through all queries and calculate the number of searches, assume you are given a list of queries and their number of searches, which is the output of another map reduce problem - Word Count.

The key of the map function is the document id which you can ignore it. The value of the map function is a document instance which contains two member variables, word and count. e.g. "hello 100", that means the query "hello" has been searched 10 times. The output the the map function depending on your algorithm, we won't check it so you can output anything you want as key-value pairs.

The key, value of the reduce function is depending on what you output in the map function. The output of the reduce function is key-value pairs where the key is the prefix, the value is top 10 queries and their counts. Use the Document class to wrap them.

在线评测地址: http://www.lintcode.com/problem/google-suggestion-map-reduce/

idea by Alan 4/11/2019
concise, modular, minHeap
Idea is same as offline top k frequent words

