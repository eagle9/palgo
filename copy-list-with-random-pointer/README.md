138. Copy List with Random Pointer
Medium 1646 446 Favorite Share

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Example 1:
Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.

Note:
You must return the copy of the given head as a reference to the cloned list.
Accepted 256,631
Submissions 926,499

Contributor LeetCode

Topic: Hash Table, Linked List
Similar:
Clone Graph Medium

Companies:
0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Amazon | 36 Bloomberg | 16 Microsoft | 15 Facebook | 8 Capital One | 7 Google | 4 Expedia | 3 Cisco | 2 Oracle | 2

Hint 1
Just iterate the linked list and create copies of the nodes on the go. Since a node can be referenced from multiple nodes due to the random pointers, make sure you are not making multiple copies of the same node.
Hint 2
You may want to use extra space to keep old node ---> new node mapping to prevent creating multiples copies of same node.
Hint 3
We can avoid using extra space for old node ---> new node mapping, by tweaking the original linked list. Simply interweave the nodes of the old and copied list. For e.g.
Old List: A --> B --> C --> D
Hint 4
InterWeaved List: A --> A' --> B --> B' --> C --> C' --> D --> D'
The interweaving is done using next pointers and we can make use of interweaved structure to get the correct reference nodes for random pointers.
