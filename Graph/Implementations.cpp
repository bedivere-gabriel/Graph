#include "Data.h"
#include <iostream>
#include <list>
#include <vector>
#include <string>

void AdjacencyListGraph::createAdjacencyListGraph(int v, std::string names[]) {
	V = v;
	places = new std::string[v];
	adj = new std::list <std::pair<int, int>>[V];
	places = names;

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < places[i].size(); j++) {
			places[i][j] = toupper(places[i][j]);
		}
	}
}

void AdjacencyListGraph::addEdge(int u, int v, int w) {
	adj[u].push_back({v, w});
}

void AdjacencyListGraph::listPrint() {
	for (int v = 0; v < V; ++v) {
		std::cout << places[v] << "\t";
		for (auto x : adj[v]) {
			std::cout << " -> " << places[x.first] << "(" << x.second << ")";
		}
		std::cout << std::endl;
	}
}

void AdjacencyListGraph::DFSUtil(int v, bool visited[]) {
	visited[v] = true;
	std::cout << places[v] << "\t";

	std::list<std::pair<int, int>>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[i->first])
			DFSUtil(i->first, visited);
}

void AdjacencyListGraph::DFS(int v) {
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	DFSUtil(v, visited);
}

void AdjacencyListGraph::BFS(int s) {
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	std::list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	std::list<std::pair<int, int>>::iterator i;
	while (!queue.empty()) {
		s = queue.front();
		std::cout << places[s] << "\t";
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); ++i) {
		
			if (!visited[i->first]) {
				visited[i->first] = true;
				queue.push_back(i->first);
			}
		}
		
	}
}

AdjacencyListGraph::~AdjacencyListGraph() {
	delete[] adj;
}

std::vector<std::vector<int>> AdjacencyListGraph::convert(std::list <std::pair<int, int>>* adj, int V) {

	std::vector<std::vector<int> > matrix(V, std::vector<int>(V, 0));
	std::list <std::pair<int, int>>* ADJM = adj;
	
	for (int i = 0; i < V; i++) {
		for (auto j : ADJM[i]) {
			matrix[i][j.first] = j.second;
		}
	}

	return matrix;
}

void AdjacencyListGraph::printMatrix(std::list <std::pair<int, int>>* adj, int V) {

	adjMatrix = convert(adj, V);

	std::cout << "\t";
	for (int i = 0; i < V; i++) {
		std::cout << places[i] << "\t";
	}
	std::cout << std::endl;
	for (int i = 0; i < V; i++) {
		std::cout << places[i] << "\t";
		for (int j = 0; j < V; j++) {
			std::cout << adjMatrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void AdjacencyListGraph::displayMatrix() {
	printMatrix(adj, V);
}

int AdjacencyListGraph::minDistance(int dist[], bool sptSet[]) {
	int min = INT_MAX, min_index = 0;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void AdjacencyListGraph::DijkstraAlgo(std::vector<std::vector<int>> matrix, int start, int finish) {
	int* dist;
	dist = new int[V]; 

	bool* sptSet; 
	sptSet = new bool[V];
	
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[start] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < V; v++)

			if (!sptSet[v] && matrix[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + matrix[u][v] < dist[v])
				dist[v] = dist[u] + matrix[u][v];
	}

	printSolution(dist, finish);
}

void AdjacencyListGraph::printSolution(int dist[], int finish) {
	for (int i = 0; i < V; i++)
		if (i == finish)
			std::cout << "Path Cost: " << dist[i] << std::endl;
}

void AdjacencyListGraph::displayMinPathDistance(int start, int finish) {
	DijkstraAlgo(adjMatrix, start, finish);
}