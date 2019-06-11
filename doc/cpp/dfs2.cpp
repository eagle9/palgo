// C++ program to print DFS traversal from 
// a given vertex in a given graph 
#include<iostream> 
#include<list> 
#include<vector>
using namespace std; 

// Graph class represents a directed graph 
// using adjacency list representation 
class Graph { 
	int V; // No. of vertices 
	// Pointer to an array containing adjacency lists 
	vector<vector<int>> adj; 
public: 
	Graph(int V); // Constructor 
	void addEdge(int u, int v); 
	// DFS traversal of the vertices reachable from v 
	void dfs(int v, vector<bool>& visited); 
}; 

Graph::Graph(int V) { 
	this->V = V; 
	adj = vector<vector<int>>(V,vector<int>()); 
} 

void Graph::addEdge(int u, int v) { 
	adj[u].push_back(v); // Add w to v’s list. 
} 

void Graph::dfs(int v, vector<bool>& visited) { 
	// Mark the current node as visited and print it 
	visited[v] = true; 
	cout << v << " "; 

	// Recur for all the vertices adjacent to this vertex 
	for (int u : adj[v]){ 
		if (!visited[u]) dfs(u, visited); 
	}
} 


int main() { 
	// Create a graph given in the above diagram 
	/*
	   0   --> 1
               | 
			   v
		\-----2  ---->3]

	*/
	int n = 4;
	Graph g(n); 
	g.addEdge(0, 1); g.addEdge(0, 2); 
	g.addEdge(1, 2); g.addEdge(2, 0); 
	g.addEdge(2, 3); g.addEdge(3, 3); 
	vector<bool> visited(n, false);
	cout << "Following is Depth First Traversal(starting from vertex 2) \n"; 
	g.dfs(2, visited); 
	printf("Expected: 2 0 1 3\n");

	return 0; 
} 

