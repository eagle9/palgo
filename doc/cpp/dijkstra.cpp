// Program to find Dijkstra's shortest path using  priority_queue 
#include<bits/stdc++.h> 
#include <list>
using namespace std; 

// iPair ==> Integer Pair 
typedef pair<int, int> iPair; 

// This class represents a directed graph using adjacency list representation 
class Graph { 
	int V; // No. of vertices 
	// In a weighted graph, we need to store vertex and weight pair for every edge 
	list< pair<int, int> > *adj;  //adj[u] = list of v,w 

public: 
	Graph(int V); // Constructor 
	void addEdge(int u, int v, int w); 
	void shortestPath(int s); 
}; 

// Allocates memory for adjacency list 
Graph::Graph(int V) { 
	this->V = V; 
	adj = new list<iPair> [V]; 
} 

void Graph::addEdge(int u, int v, int w) { 
	adj[u].push_back(make_pair(v, w)); 
	adj[v].push_back(make_pair(u, w)); 
} 

// Prints shortest paths from src to all other vertices 
void Graph::shortestPath(int src) { 
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq; //iPair of distance and vertex, smaller distance at top  

	// Create a vector for distances and initialize all distances as INT_MAX 
	vector<int> dist(V, INT_MAX); 

	pq.push(make_pair(0, src)); 
	dist[src] = 0; 

	/* Looping till priority queue becomes empty (or all 
	distances are not finalized) */
	while (!pq.empty()) { 
		int u = pq.top().second; 
		pq.pop(); 

		// 'i' is used to get all adjacent vertices of a vertex 
		//list< pair<int, int> >::iterator i; 
		for (auto i = adj[u].begin(); i != adj[u].end(); ++i) { 
			// Get vertex label and weight of current adjacent of u. 
			int v = (*i).first; 
			int weight = (*i).second; 

			// If there is shorted path to v through u. 
			if (dist[v] > dist[u] + weight) { 
				dist[v] = dist[u] + weight; //update dist[v] from src 
				pq.push(make_pair(dist[v], v)); 
			} 
		} 
	} 

	cout << "Vertex Distance from Source" << endl; 
	for (int i = 0; i < V; ++i) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

// Driver program to test methods of graph class 
int main() { 
	// create the graph given in above fugure 
	int V = 9; 
	Graph g(V); 

	// making above shown graph 
	g.addEdge(0, 1, 4); 
	g.addEdge(0, 7, 8); 
	g.addEdge(1, 2, 8); 
	g.addEdge(1, 7, 11); 
	g.addEdge(2, 3, 7); 
	g.addEdge(2, 8, 2); 
	g.addEdge(2, 5, 4); 
	g.addEdge(3, 4, 9); 
	g.addEdge(3, 5, 14); 
	g.addEdge(4, 5, 10); 
	g.addEdge(5, 6, 2); 
	g.addEdge(6, 7, 1); 
	g.addEdge(6, 8, 6); 
	g.addEdge(7, 8, 7); 

	g.shortestPath(0); 

	return 0; 
} 

