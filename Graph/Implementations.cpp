#include "Data.h"
#include <iostream>
#include <list>
#include <string>

void AdjecencyListGraph::createAdjecencyListGraph(int v, std::string names[]) {
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

void AdjecencyListGraph::addEdge(int u, int v, int w) {
	adj[u].push_back({v, w});
}

void AdjecencyListGraph::listPrint() {
	for (int v = 0; v < V; ++v) {
		std::cout << places[v] << "\t";
		for (auto x : adj[v]) {
			std::cout << " -> " << places[x.first] << "(" << x.second << ")";
		}
		std::cout << std::endl;
	}
}

void AdjecencyListGraph::DFSUtil(int v, bool visited[]) {
	visited[v] = true;
	std::cout << places[v] << "\t";

	std::list<std::pair<int, int>>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[i->first])
			DFSUtil(i->first, visited);
}

void AdjecencyListGraph::DFS(int v) {
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	DFSUtil(v, visited);
}

void AdjecencyListGraph::BFS(int s) {
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

void AdjecencyListGraph::pathCost(std::string start, std::string finish) {
	int minimumCost = INT_MAX;
	bool finishFound = false, startFound = false;
	int startIndex = 0, finishIndex = 0;
	bool pathFound;

	for (int i = 0; i < start.size(); i++) 
		start[i] = toupper(start[i]);
	
	for (int i = 0; i < finish.size(); i++)
		finish[i] = toupper(finish[i]);

	for (int i = 0; i < V; i++) {
		if (places[i] == start) {
			startFound = true;
			startIndex = i;
		}
	}

	for (int i = 0; i < V; i++) {
		if (places[i] == finish) {
			finishFound = true;
			startIndex = i;
		}
	}

	if (finishFound && startFound) {
		if (startIndex == finishIndex)
			std::cout << "Path Cost: " << 0 << std::endl;

		else {
			printMatrix(convert(adj, V), V);
		}
	}
	else
		std::cout << "Start and/or Finish not found" << std::endl;
}

AdjecencyListGraph::~AdjecencyListGraph() {
	delete[] adj;
}

std::vector<std::vector<int>> AdjecencyListGraph::convert(std::list <std::pair<int, int>>* adj, int V) {

	std::vector<std::vector<int> > matrix(V, std::vector<int>(V, 0));
	std::list <std::pair<int, int>>* ADJM = adj;
	
	for (int i = 0; i < V; i++) {
		for (auto j : ADJM[i]) {
			matrix[i][j.first] = j.second;
		}
	}

	return matrix;
}

void AdjecencyListGraph::printMatrix(std::vector<std::vector<int>> adj, int V) {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			std::cout << adj[i][j] << "   ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}