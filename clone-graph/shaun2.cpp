/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
/*
shaun got jz linhuchong bfs idea, copy nodes first then edges second
coded after 2 days after heard the idea
idea:  bfs iterate the graph, for each node, create a new node with the same val and store in hashmap
since we are given a connected undirected graph, bfs we will get all nodes of the graph. 

then for each node, for all its neighbors,  fill node1's neighbors

accepted first sub, after fixing typoe n.neighbors ==> n->neighbors
runtime 28ms, faster than 99.54%, mem less than 69%
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node*> q;
        q.push(node);
        unordered_set<Node*> visited;
        visited.insert(node);
        while (!q.empty()) {
            Node* n = q.front(); q.pop();
            for (auto nb: n->neighbors) {
                if (!visited.count(nb)) {
                    visited.insert(nb);
                    q.push(nb);
                }
            }
        }
        
        for (Node* n: visited) {
            Node* n2 = new Node();
            n2->val = n->val;
            n2->neighbors = vector<Node*>();
            m[n] = n2;
        }
        for (Node* n: visited) {
            Node* n2 = m[n];
            for (Node* nb: n->neighbors) {
                Node* nb2 = m[nb];
                n2->neighbors.push_back(nb2);
            }
        }
        return m[node];
    }
private:
    unordered_map<Node*, Node*> m;
};

