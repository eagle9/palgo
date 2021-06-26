382. Linked List Random Node
Medium 447 135 Favorite Share

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();

Accepted 60.5K
Submissions 119.8K

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

Google | 2

Similar
Random Pick Index Medium

Topic: Reservoir Sampling
