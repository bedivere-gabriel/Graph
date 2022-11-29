#pragma once

#include <list>
#include <vector>
#include <iostream>

class AdjacencyListGraph {
private:
	int V;
	std::list <std::pair<int, int>>* adj;
	std::vector <std::vector<int>> adjMatrix;
	void DFSUtil(int v, bool visited[]);
	std::string* places;
	std::vector<std::vector<int> > convert(std::list <std::pair<int, int>>* adj, int V);
	int minDistance(int dist[], bool sptSet[]);
	void DijkstraAlgo(std::vector<std::vector<int>> matrix, int start, int finish);
	void printSolution(int dist[], int finish);

public:
	void createAdjacencyListGraph(int v, std::string names[]);
	void addEdge(int u, int v, int w);
	void listPrint();
	void DFS(int v);
	void BFS(int s);
	void printMatrix(std::list <std::pair<int, int>>* adj, int V);
	void displayMatrix();
	void displayMinPathDistance(int start, int finish);
	~AdjacencyListGraph();
};