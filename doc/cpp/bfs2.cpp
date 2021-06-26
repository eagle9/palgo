// Program to print BFS traversal from a given 
// source vertex. BFS(int s) traverses vertices 
// reachable from s. 
#include<iostream> 
#include <list> 
#include <vector>
#include <queue>

using namespace std; 

// This class represents a directed graph using 
// adjacency list representation 
class Graph { 
	int V; // No. of vertices 

	// Pointer to an array containing adjacency lists 
	list<int> *adj; 
public: 
	Graph(int V); // Constructor 
	// function to add an edge to graph 
	void addEdge(int v, int u); 
	// prints BFS traversal from a given source s 
	void BFS(int s); 
}; 

Graph::Graph(int V) { 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int u) { 
	adj[v].push_back(u); // Add u to v’s list. 
} 

void Graph::BFS(int s) { 
	// Mark all the vertices as not visited 
	/*
	bool *visited = new bool[V]; 
	for(int i = 0; i < V; i++) 
		visited[i] = false;*/ 
	vector<bool> visited(V, false);

	// Create a queue for BFS 
	//list<int> queue; //okay too
	queue<int> queue; 

	// Mark the current node as visited and enqueue it 
	visited[s] = true; 
	queue.push(s);
	//queue.push_back(s); //list based queue 

	// 'i' will be used to get all adjacent // vertices of a vertex 
	//list<int>::iterator i; 

	while(!queue.empty()) { 
		// Dequeue a vertex from queue and print it 
		s = queue.front(); 
		cout << s << " "; 
		//queue.pop_front();  //list based
		queue.pop();

		// Get all adjacent vertices of the dequeued vertex s. If a adjacent has not been visited, 
		// then mark it visited and enqueue it 
		for (auto i = adj[s].begin(); i != adj[s].end(); ++i) { 
			if (!visited[*i]) { 
				visited[*i] = true; 
				queue.push(*i);
				//queue.push_back(*i); //list based 
			} 
		} 
	} 
} 

// Driver program to test methods of graph class 
int main() { 
	// Create a graph given in the above diagram 
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3); 
/*
    0 -->1 
		 |
         v 
     \-- 2 -->3]
*/

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n"; 
	g.BFS(2); 
	cout <<  endl;
	cout << "expected: 2 3 0 1 or 2 0 3 1" << endl;

	return 0; 
} 

